/*
 * Copyright 2015 Clément Vuchener
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// bennyPerth@gmail.com

// 12 October 2015
// copied the k40-set-colour code from github (Clément Vuchene)
// app is console based and didn't have a dialogue for selecting
// a colour.
// Wrapped some Qt code around it to give it a GUI with combo boxes and
// a colour selection dialogue.

// 13 October 2015
// added buttons with favourite colours
// changed compares to qmaps

// 14 October 2015
// had to reboot this morning and for some reason both the original code
// from Clément Vuchener and my code is using the profiles so that I
// now get a colour per profile. It has also hung up a couple times
// (out of about 20 tests) and cancelling it at the command line and
// restarting it were successful.
// Sent a note to Clément Vuchener last night and he replied. Will put this
// in my github repositories.
// Adding buttons to show current profile colours

// 18 October 2015
// Not hanging now. Added current colours to the profile buttons and the combobox.
// Some colours are not the same as the keyboard but k50-set-colour and my app
// give the same results. Makes one wonder what the mode of 'thue colour' does.


// TODO
// create a daemon so app can run in user mode.




#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QColorDialog>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>

// followiing moved to header
//extern "C" {
//#include <unistd.h>
//#include <getopt.h>
//#include <libusb-1.0/libusb.h>
//}

QString version  = "a10";

#define CORSAIR_ID	0x1b1c
#define CORSAIR_K40_ID	0x1b0e

#define DELAY	200000

#define REQUEST_STATUS	4
#define REQUEST_STATUS_EXTENDED	5
#define REQUEST_SWITCH_PROFILE	20
#define REQUEST_SET_ANIM	49
#define REQUEST_SET_COLOR_CONTROL	50
#define REQUEST_SET_COLOUR	51
#define REQUEST_SET_COLOR_MODE	56

#define COLOR_CONTROL_SW	0x0600
#define COLOR_CONTROL_HW	0x0a00


// uint8_t  = unsigned char
// uint16_t = unsigned int
// uint32_t = unsigned long long
// breakdown of status bytes (relative to 1)
//  1 - unknown
//  2 - colour mode - brightness (0->3)
//  3 - control mode (06 = software, 0A = hardware)
//  4 - animation (0 = off, 1 = pulse, 2 = cycle)
//  5 -> 7 colour (RGB)
//  8 - profile (0-3) - M1, M2, M3  keys
//  9 -




QMap<QString, uint16_t> controlModeMap;
QMap<QString, uint16_t> colourModeMap;
QMap<uint16_t, QString> animationMap;


int redColour = 128;
int greenColour = 0;
int blueColour = 0;
QColor currentColour = QColor(redColour,greenColour, blueColour);
QString wrapInRedPrefix = "<p class='small'><FONT COLOR='#ff00FF'>";
QString wrapInColourSuffix = "</FONT>";

QString wrapInColourPrefix1 = "<p class='small'><FONT COLOR='#"; //
QString wrapColour = "123456";
QString wrapInColourPrefix2 = "'>";

int profile = 0;
int startingProfile = 0;
int currentProfile = 0;
QString buildColour = "";

int ret;

libusb_device_handle *device;
libusb_context *context;

// ................................................................................... //
// .................................. intialisation .................................. //
// ................................................................................... //
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // set up combobox options
  ui->cboProfile->addItem("M1");
  ui->cboProfile->addItem("M2");
  ui->cboProfile->addItem("M3");


  controlModeMap.insert("Software", COLOR_CONTROL_SW);
  controlModeMap.insert("Hardware", COLOR_CONTROL_HW);
  QMapIterator<QString, uint16_t> controlModeIterator(controlModeMap);

  while (controlModeIterator.hasNext()) {
    controlModeIterator.next();
    ui->cboControlMode->addItem(controlModeIterator.key());
  }

  //
  colourModeMap.insert("True Colour", 0);
  colourModeMap.insert("Max Brightness", 1);
  QMapIterator<QString, uint16_t> colourModeIterator(colourModeMap);

  while (colourModeIterator.hasNext()) {
    colourModeIterator.next();
    ui->cboColourMode->addItem(colourModeIterator.key());
  }


  // create animationMap in value sequence so that 'Off' comes first
  animationMap.insert(0, "Off");
  animationMap.insert(1, "Pulse");
  animationMap.insert(2, "Cycle");
  QMapIterator<uint16_t, QString> animationValueIterator(animationMap);

  while (animationValueIterator.hasNext()) {
    animationValueIterator.next();
    ui->cboAnimation->addItem(animationValueIterator.value());
  }

  ui->lblVersion->setText("version "+version);

//  setStyleSheet("color: black; background-color: QColor(204,223,230) ;");
//  setStyleSheet("color: QColor(23,23,30);");

  // favourite keyboard colours
  QPalette* palettex = new QPalette();
  palettex->setColor(QPalette::Button,QColor(121,50,255));
  ui->btnFavourite1->setPalette(*palettex);
  palettex->setColor(QPalette::Button,QColor(81,155,54));
  ui->btnFavourite2->setPalette(*palettex);
  palettex->setColor(QPalette::Button,QColor(255,85,0));
  ui->btnFavourite3->setPalette(*palettex);
  palettex->setColor(QPalette::Button,QColor(121,5,155));
  ui->btnFavourite4->setPalette(*palettex);
  palettex->setColor(QPalette::Button,QColor(160,222,114));
  ui->btnFavourite5->setPalette(*palettex);
  palettex->setColor(QPalette::Button,QColor(255,244,114));
  ui->btnFavourite6->setPalette(*palettex);
  palettex->setColor(QPalette::Button,QColor(82,75,121));
  ui->btnFavourite7->setPalette(*palettex);
  palettex->setColor(QPalette::Button,QColor(121,126,62));
  ui->btnFavourite8->setPalette(*palettex);
  palettex->setColor(QPalette::Button,QColor(227,214,34));
  ui->btnFavourite9->setPalette(*palettex);


  QString centreTitle = "QGroupBox::title {  background-color: transparent; \
      subcontrol-position: top center; \
      padding:0 1px; } ";
  QString darkBorder = "QGroupBox { border: 2px solid gray; margin-top: 1px; border-radius: 15px; } ";
  QString groupStyle = centreTitle + " " + darkBorder;

  qApp->setStyleSheet(groupStyle);

  connect(ui->cboProfile, SIGNAL(currentIndexChanged(int)),
          this, SLOT(cboProfileChanged(int)));
  connect(ui->cboControlMode, SIGNAL(currentIndexChanged(int)),
          this, SLOT(cboControlModeChanged(int)));
  connect(ui->cboColourMode, SIGNAL(currentIndexChanged(int)),
          this, SLOT(cboColourModeChanged(int)));
  connect(ui->cboAnimation, SIGNAL(currentIndexChanged(int)),
          this, SLOT(cboAnimationChanged(int)));


  if (0 != (ret = libusb_init (&context))) {
    fprintf (stderr, "Failed to initialise libusb: %s\n", libusb_error_name (ret));
    return ;
  }

  libusb_set_debug (context, LIBUSB_LOG_LEVEL_WARNING);
  if (!(device = libusb_open_device_with_vid_pid (context, CORSAIR_ID, CORSAIR_K40_ID))) {
    ui->lblDeviceStatus->setText(wrapInRedPrefix+"Device not found or Only root can access the K40"+wrapInColourSuffix);
    return ;
  }

  statusStructure testArray =    getKeyboardStatus();
  startingProfile = testArray.profile;
  char colourArray[16];

  sprintf(colourArray, "#%02hhX%02hhX%02hhX", testArray.colourRed, testArray.colourGreen, testArray.colourBlue );

//  qDebug() << "colours" << testArray.colourRed;
//  qDebug() << "aaaaa" << (uint8_t)testArray.colourRed << (uint8_t)testArray.colourGreen << (uint8_t)testArray.colourBlue;
//  qDebug() << "bbbbb" << colourArray;

  // benny just a proof of concept vjvj
  palettex->setColor(QPalette::Button,QColor(colourArray));
  ui->cboProfile->setPalette(*palettex);
  ui->cboProfile->setCurrentIndex(startingProfile-1);

  for( int i = 1; i < 4; i++ ) {
    ret = libusb_control_transfer (device,
                 LIBUSB_ENDPOINT_OUT | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
                 REQUEST_SWITCH_PROFILE, i, 0,
                 nullptr, 0, 0);

    usleep (DELAY);

    statusStructure testArray =    getKeyboardStatus();
    sprintf(colourArray, "#%02hhX%02hhX%02hhX", testArray.colourRed, testArray.colourGreen, testArray.colourBlue );

    palettex->setColor(QPalette::Button,QColor(colourArray));
    qDebug() << "abc";
    setProfileColours(testArray.profile, *palettex);

  }  // end of for loop

  // restore original profile
  ret = libusb_control_transfer (device,
               LIBUSB_ENDPOINT_OUT | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
               REQUEST_SWITCH_PROFILE, startingProfile, 0,
               nullptr, 0, 0);

}


void MainWindow::cboProfileChanged(int index) {
  QPalette* palettex = new QPalette();
  profile = index+1;
  ret = libusb_control_transfer (device,
               LIBUSB_ENDPOINT_OUT | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
               REQUEST_SWITCH_PROFILE, profile, 0,
               nullptr, 0, 0);

  usleep (DELAY);

  statusStructure testArray = getKeyboardStatus();
  char colourArray[16];

  sprintf(colourArray, "#%02hhX%02hhX%02hhX", testArray.colourRed, testArray.colourGreen, testArray.colourBlue );
  palettex->setColor(QPalette::Button,QColor(colourArray));
  ui->cboProfile->setPalette(*palettex);

  qDebug() << "xay";
  setProfileColours(profile, *palettex);
}

void MainWindow::setProfileColours(int parsedProfile, QPalette palettex) {
//  QPalette* palettex = new QPalette();
  switch (parsedProfile) {
    case 1:
      ui->btnM1->setPalette(palettex);
    break;
  case 2:
      ui->btnM2->setPalette(palettex);
    break;
  case 3:
      ui->btnM3->setPalette(palettex);
    break;
  default:
    qDebug() << "profile is invalid" << parsedProfile;
    break;
  }  // end of switch

}


void MainWindow::cboControlModeChanged(int index) {
  QString text = ui->cboControlMode->itemText(index);
  uint16_t control = controlModeMap.value(text);

  ret = libusb_control_transfer (device,
               LIBUSB_ENDPOINT_OUT | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
               REQUEST_SET_COLOR_CONTROL, control, 0,
               nullptr, 0, 0);

  if (ret < 0) {
    ui->lblDeviceStatus->setText(wrapInRedPrefix + "Failed to set colour control:" + libusb_error_name (ret) + wrapInColourSuffix);
    return ;
  }
  fprintf (stderr, "Set colour control to 0x%04hX.\n", control);
  usleep (DELAY);
}


void MainWindow::cboColourModeChanged(int index) {
  QString text = ui->cboColourMode->itemText(index);
  uint16_t mode = colourModeMap.value(text);

  ret = libusb_control_transfer (device,
               LIBUSB_ENDPOINT_OUT | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
               REQUEST_SET_COLOR_MODE, mode, 0,
               nullptr, 0, 0);

  if (ret < 0) {
    ui->lblDeviceStatus->setText(wrapInRedPrefix + "Failed to set colour mode:" + libusb_error_name (ret) + wrapInColourSuffix);
    return;
  }

  fprintf (stderr, "Set colour mode to: 0x%04hX.\n", mode);
  usleep (DELAY);
}


void MainWindow::cboAnimationChanged(int index) {
  QString text = ui->cboAnimation->itemText(index);

  uint16_t anim = animationMap.key(text);

  ret = libusb_control_transfer (device,
               LIBUSB_ENDPOINT_OUT | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
               REQUEST_SET_ANIM, 0, anim,
               nullptr, 0, 0);
  if (ret < 0) {
    ui->lblDeviceStatus->setText(wrapInRedPrefix + "Failed to set animation:" + libusb_error_name (ret) + wrapInColourSuffix);
    return ;
  }
  fprintf (stderr, "Set animation to 0x%04hX.\n", anim);
  usleep (DELAY);
}

// ................................................................................... //
// ............................. get new keyboard colour ............................. //
// ................................................................................... //
void MainWindow::on_btnSelectColour_clicked() {
  uint8_t data[10];

  ret = libusb_control_transfer (device,
               LIBUSB_ENDPOINT_IN | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
               REQUEST_STATUS, 0, 0,
               data, sizeof (data), 0);
  if (ret < 0) {
    ui->lblDeviceStatus->setText(wrapInRedPrefix + "Failed to read status:" + libusb_error_name (ret) + wrapInColourSuffix);
    return;
  }

  // ............................. get current colour of leds ............................. //
  redColour = data[4];
  greenColour = data[5];
  blueColour = data[6];
  currentColour = QColor(redColour,greenColour, blueColour);

  // use dialogue to get another colour
  QColor newColour = QColorDialog::getColor(currentColour, this);

  redColour = newColour.red();
  blueColour = newColour.blue();
  greenColour = newColour.green();
  currentColour = QColor(redColour,greenColour, blueColour);
  qDebug() << "new colour" << "red:" << redColour << "green:" << greenColour << "blue:" << blueColour;
}


void MainWindow::on_btnFavourite1_clicked() {
  currentColour = ui->btnFavourite1->palette().button().color();
  redColour = currentColour.red(); greenColour = currentColour.green(); blueColour = currentColour.blue();
}

void MainWindow::on_btnFavourite2_clicked() {
  currentColour = ui->btnFavourite2->palette().button().color();
  redColour = currentColour.red(); greenColour = currentColour.green(); blueColour = currentColour.blue();
}

void MainWindow::on_btnFavourite3_clicked() {
  currentColour = ui->btnFavourite3->palette().button().color();
  redColour = currentColour.red(); greenColour = currentColour.green(); blueColour = currentColour.blue();
}

void MainWindow::on_btnFavourite4_clicked() {
  currentColour = ui->btnFavourite4->palette().button().color();
  redColour = currentColour.red(); greenColour = currentColour.green(); blueColour = currentColour.blue();
}

void MainWindow::on_btnFavourite5_clicked() {
  currentColour = ui->btnFavourite5->palette().button().color();
  redColour = currentColour.red(); greenColour = currentColour.green(); blueColour = currentColour.blue();
}

void MainWindow::on_btnFavourite6_clicked() {
  currentColour = ui->btnFavourite6->palette().button().color();
  redColour = currentColour.red(); greenColour = currentColour.green(); blueColour = currentColour.blue();
}

void MainWindow::on_btnFavourite7_clicked() {
  currentColour = ui->btnFavourite7->palette().button().color();
  redColour = currentColour.red(); greenColour = currentColour.green(); blueColour = currentColour.blue();
}

void MainWindow::on_btnFavourite8_clicked() {
  currentColour = ui->btnFavourite8->palette().button().color();
  redColour = currentColour.red(); greenColour = currentColour.green(); blueColour = currentColour.blue();
}

void MainWindow::on_btnFavourite9_clicked() {
  currentColour = ui->btnFavourite9->palette().button().color();
  redColour = currentColour.red(); greenColour = currentColour.green(); blueColour = currentColour.blue();
}



void MainWindow::on_btnCancel_clicked() {
  close();
}


void MainWindow::on_btnUpdate_clicked() {
//  qDebug() << "btnUpdate" << "red:" << redColour << "green:" << greenColour << "blue:" << blueColour;
  char colourText[80];
  char colourHex[6];

  //    green     shift left 8  OR  red                shift left 8     OR blue
  //    colour[1] <<            |   colour[0], profile << 8             |  colour[2]

  //  wValue(high) 		Green   - colour[1]
  //  wValue(low) 		Red     - colour[0]
  //  wIndex(high) 		Target  - profile
  //  wIndex(low) 		Blue    - colour[2]

  ret = libusb_control_transfer (device,
               LIBUSB_ENDPOINT_OUT | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
               REQUEST_SET_COLOUR, greenColour << 8 | redColour, profile << 8 | blueColour,
               nullptr, 0, 0);
  if (ret < 0) {
    ui->lblDeviceStatus->setText(wrapInRedPrefix + "Failed to set colour:" + libusb_error_name (ret) + wrapInColourSuffix);
  }

//  if (profile == 0)
//    fprintf (stderr, "Set colour %02hhX%02hhX%02hhX.\n", redColour, greenColour, blueColour);
//  else
//    fprintf (stderr, "Set colour %02hhX%02hhX%02hhX for profile %d.\n", redColour, greenColour, blueColour, profile);

  sprintf(colourHex, "%02hhX%02hhX%02hhX", redColour, greenColour, blueColour);
  sprintf(colourText, "red: %hhu green: %hhu blue: %hhu set for profile %d", redColour, greenColour, blueColour, profile);

  wrapColour =  colourHex;
  QString wrapString = wrapInColourPrefix1 + wrapColour + wrapInColourPrefix2;
  ui->lblStatus->setText(wrapString +colourText + wrapInColourSuffix);

  // ensure combobox has new colour
  cboProfileChanged(profile-1);
//  setProfileColour(profile);


}


statusStructure MainWindow::getKeyboardStatus () {
  statusStructure returnValues;
  uint8_t data[20];
  char statusText[100];

  // breakdown of status bytes (relative to 1)
  //  1 - unknown
  //  2 - colour mode - brightness (0->3)
  //  3 - control mode (06 = software, 0A = hardware)
  //  4 - animation (0 = off, 1 = pulse, 2 = cycle)
  //  5 -> 7 colour (RGB)
  //  8 - profile (0-3) - M1, M2, M3  keys
  //  9 -


  // if animation set off, all 3 profiles are active
  // if animation pulse, active profile pulses
  // if animation set to cycle, profile keys are ignored
  // not sure of the signifacance of a profile of 0
  // what does control mode do?
  //


  ret = libusb_control_transfer (device,
               LIBUSB_ENDPOINT_IN | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
               REQUEST_STATUS, 0, 0,
               data, sizeof (data), 0);
  if (ret < 0) {
    char errorMessage[50];
    sprintf (errorMessage, "Failed to read status: %s (%s)",
         libusb_error_name (ret), strerror (errno));
    ui->lblStatus->setText(errorMessage);

    returnValues.unknown1 = 255;
    return returnValues;
  }

  // ............................. show colour of leds ............................. //

  sprintf(statusText, "%02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX   %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX",
         data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15], data[16], data[17], data[18], data[19] );
  ui->lblDeviceStatus->setText(statusText);


  char colourText[80];
  sprintf(colourText, "red: %hhu green: %hhu blue: %hhu\n", data[4], data[5], data[6]);
  ui->lblStatus->setText(colourText);

  qDebug() << "--------------------------------------------------------";
  qDebug() << statusText;
  qDebug() << colourText ;

  returnValues.profile = data[7];
  returnValues.colourRed = data[4];
  returnValues.colourGreen = data[5];
  returnValues.colourBlue = data[6];
  return returnValues;
}


MainWindow::~MainWindow() {
  delete ui;

  libusb_close (device);
  libusb_exit (context);

}
