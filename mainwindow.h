#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

extern "C" {
#include <unistd.h>
#include <getopt.h>
#include <libusb-1.0/libusb.h>
}

typedef struct {
    uint8_t unknown1,
    colourMode,
    controlMode,
    animation,
    colourRed,
    colourGreen,
    colourBlue,
    profile,
    unknown9,
    unknown10, unknown11, unknown12, unknown13, unknown14,
    unmnown15, unknown16, unknown17, unknown18, unknown19, unknown20;
} statusStructure;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;


private slots:
    void cboProfileChanged(int);
    void cboControlModeChanged(int);
    void cboColourModeChanged(int);
    void cboAnimationChanged(int);

    void on_btnSelectColour_clicked();

    void on_btnFavourite1_clicked();
    void on_btnFavourite2_clicked();
    void on_btnFavourite3_clicked();
    void on_btnFavourite4_clicked();
    void on_btnFavourite5_clicked();
    void on_btnFavourite6_clicked();
    void on_btnFavourite7_clicked();
    void on_btnFavourite8_clicked();
    void on_btnFavourite9_clicked();

    void on_btnCancel_clicked();
    void on_btnUpdate_clicked();

public:

protected:
    statusStructure getKeyboardStatus();
    void setProfileColours(int, QPalette);


    };
#endif // MAINWINDOW_H
