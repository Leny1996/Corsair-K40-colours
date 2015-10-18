/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnCancel;
    QPushButton *btnUpdate;
    QPushButton *btnSelectColour;
    QLabel *lblTitle;
    QLabel *lblStatus;
    QLabel *lblVersion;
    QLabel *lblDeviceStatus;
    QGroupBox *groupFavourites;
    QPushButton *btnFavourite1;
    QPushButton *btnFavourite2;
    QPushButton *btnFavourite3;
    QPushButton *btnFavourite4;
    QPushButton *btnFavourite5;
    QPushButton *btnFavourite6;
    QGroupBox *groupOptions;
    QLabel *lblControlMode;
    QComboBox *cboColourMode;
    QComboBox *cboAnimation;
    QLabel *lblProfile;
    QComboBox *cboProfile;
    QComboBox *cboControlMode;
    QLabel *lblAnimation;
    QLabel *lblColourMode;
    QLabel *lblStatus_2;
    QGroupBox *groupProfileColours;
    QPushButton *btnM1;
    QPushButton *btnM2;
    QPushButton *btnM3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(767, 593);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(172, 171, 162, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 254, 244, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(213, 212, 203, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(86, 85, 81, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(115, 114, 108, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(213, 213, 208, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnCancel = new QPushButton(centralWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(480, 500, 96, 31));
        QPalette palette1;
        QBrush brush9(QColor(236, 206, 232, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        btnCancel->setPalette(palette1);
        btnUpdate = new QPushButton(centralWidget);
        btnUpdate->setObjectName(QStringLiteral("btnUpdate"));
        btnUpdate->setGeometry(QRect(630, 500, 96, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        btnUpdate->setPalette(palette2);
        btnSelectColour = new QPushButton(centralWidget);
        btnSelectColour->setObjectName(QStringLiteral("btnSelectColour"));
        btnSelectColour->setGeometry(QRect(20, 140, 96, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        btnSelectColour->setPalette(palette3);
        lblTitle = new QLabel(centralWidget);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(90, 0, 541, 21));
        QFont font;
        font.setPointSize(17);
        lblTitle->setFont(font);
        lblTitle->setAlignment(Qt::AlignCenter);
        lblStatus = new QLabel(centralWidget);
        lblStatus->setObjectName(QStringLiteral("lblStatus"));
        lblStatus->setGeometry(QRect(10, 460, 451, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lblStatus->setFont(font1);
        lblStatus->setWordWrap(true);
        lblVersion = new QLabel(centralWidget);
        lblVersion->setObjectName(QStringLiteral("lblVersion"));
        lblVersion->setGeometry(QRect(680, 0, 81, 20));
        lblDeviceStatus = new QLabel(centralWidget);
        lblDeviceStatus->setObjectName(QStringLiteral("lblDeviceStatus"));
        lblDeviceStatus->setGeometry(QRect(10, 300, 561, 31));
        lblDeviceStatus->setFont(font1);
        groupFavourites = new QGroupBox(centralWidget);
        groupFavourites->setObjectName(QStringLiteral("groupFavourites"));
        groupFavourites->setGeometry(QRect(150, 140, 231, 111));
        groupFavourites->setAlignment(Qt::AlignCenter);
        btnFavourite1 = new QPushButton(groupFavourites);
        btnFavourite1->setObjectName(QStringLiteral("btnFavourite1"));
        btnFavourite1->setGeometry(QRect(20, 30, 51, 26));
        btnFavourite2 = new QPushButton(groupFavourites);
        btnFavourite2->setObjectName(QStringLiteral("btnFavourite2"));
        btnFavourite2->setGeometry(QRect(90, 30, 51, 26));
        btnFavourite3 = new QPushButton(groupFavourites);
        btnFavourite3->setObjectName(QStringLiteral("btnFavourite3"));
        btnFavourite3->setGeometry(QRect(160, 30, 51, 26));
        btnFavourite4 = new QPushButton(groupFavourites);
        btnFavourite4->setObjectName(QStringLiteral("btnFavourite4"));
        btnFavourite4->setGeometry(QRect(20, 70, 51, 26));
        btnFavourite5 = new QPushButton(groupFavourites);
        btnFavourite5->setObjectName(QStringLiteral("btnFavourite5"));
        btnFavourite5->setGeometry(QRect(90, 70, 51, 26));
        btnFavourite6 = new QPushButton(groupFavourites);
        btnFavourite6->setObjectName(QStringLiteral("btnFavourite6"));
        btnFavourite6->setGeometry(QRect(160, 70, 51, 26));
        groupOptions = new QGroupBox(centralWidget);
        groupOptions->setObjectName(QStringLiteral("groupOptions"));
        groupOptions->setGeometry(QRect(100, 40, 551, 80));
        groupOptions->setAlignment(Qt::AlignCenter);
        lblControlMode = new QLabel(groupOptions);
        lblControlMode->setObjectName(QStringLiteral("lblControlMode"));
        lblControlMode->setGeometry(QRect(130, 30, 91, 20));
        lblControlMode->setAlignment(Qt::AlignCenter);
        cboColourMode = new QComboBox(groupOptions);
        cboColourMode->setObjectName(QStringLiteral("cboColourMode"));
        cboColourMode->setGeometry(QRect(270, 50, 111, 21));
        cboAnimation = new QComboBox(groupOptions);
        cboAnimation->setObjectName(QStringLiteral("cboAnimation"));
        cboAnimation->setGeometry(QRect(420, 50, 111, 21));
        lblProfile = new QLabel(groupOptions);
        lblProfile->setObjectName(QStringLiteral("lblProfile"));
        lblProfile->setGeometry(QRect(0, 30, 71, 20));
        lblProfile->setAlignment(Qt::AlignCenter);
        cboProfile = new QComboBox(groupOptions);
        cboProfile->setObjectName(QStringLiteral("cboProfile"));
        cboProfile->setGeometry(QRect(10, 50, 61, 21));
        cboControlMode = new QComboBox(groupOptions);
        cboControlMode->setObjectName(QStringLiteral("cboControlMode"));
        cboControlMode->setGeometry(QRect(130, 50, 91, 21));
        lblAnimation = new QLabel(groupOptions);
        lblAnimation->setObjectName(QStringLiteral("lblAnimation"));
        lblAnimation->setGeometry(QRect(430, 30, 91, 20));
        lblAnimation->setAlignment(Qt::AlignCenter);
        lblColourMode = new QLabel(groupOptions);
        lblColourMode->setObjectName(QStringLiteral("lblColourMode"));
        lblColourMode->setGeometry(QRect(270, 30, 101, 20));
        lblColourMode->setAlignment(Qt::AlignCenter);
        lblStatus_2 = new QLabel(centralWidget);
        lblStatus_2->setObjectName(QStringLiteral("lblStatus_2"));
        lblStatus_2->setGeometry(QRect(10, 270, 131, 20));
        lblStatus_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupProfileColours = new QGroupBox(centralWidget);
        groupProfileColours->setObjectName(QStringLiteral("groupProfileColours"));
        groupProfileColours->setGeometry(QRect(420, 130, 231, 61));
        groupProfileColours->setAlignment(Qt::AlignCenter);
        btnM1 = new QPushButton(groupProfileColours);
        btnM1->setObjectName(QStringLiteral("btnM1"));
        btnM1->setGeometry(QRect(20, 20, 51, 26));
        btnM2 = new QPushButton(groupProfileColours);
        btnM2->setObjectName(QStringLiteral("btnM2"));
        btnM2->setGeometry(QRect(90, 20, 51, 26));
        btnM3 = new QPushButton(groupProfileColours);
        btnM3->setObjectName(QStringLiteral("btnM3"));
        btnM3->setGeometry(QRect(160, 20, 51, 26));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnCancel->setText(QApplication::translate("MainWindow", "Cancel", 0));
        btnUpdate->setText(QApplication::translate("MainWindow", "Update", 0));
        btnSelectColour->setText(QApplication::translate("MainWindow", "Select Colour", 0));
        lblTitle->setText(QApplication::translate("MainWindow", "K40", 0));
        lblStatus->setText(QApplication::translate("MainWindow", "...", 0));
        lblVersion->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        lblDeviceStatus->setText(QApplication::translate("MainWindow", "...", 0));
        groupFavourites->setTitle(QApplication::translate("MainWindow", "Favourite colours", 0));
        btnFavourite1->setText(QString());
        btnFavourite2->setText(QString());
        btnFavourite3->setText(QString());
        btnFavourite4->setText(QString());
        btnFavourite5->setText(QString());
        btnFavourite6->setText(QString());
        groupOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
        lblControlMode->setText(QApplication::translate("MainWindow", "Control Mode", 0));
        lblProfile->setText(QApplication::translate("MainWindow", "Profile", 0));
        lblAnimation->setText(QApplication::translate("MainWindow", "Animation", 0));
        lblColourMode->setText(QApplication::translate("MainWindow", "Colour Mode", 0));
        lblStatus_2->setText(QApplication::translate("MainWindow", "Device status", 0));
        groupProfileColours->setTitle(QApplication::translate("MainWindow", "Profile colours", 0));
        btnM1->setText(QApplication::translate("MainWindow", "M1", 0));
        btnM2->setText(QApplication::translate("MainWindow", "M2", 0));
        btnM3->setText(QApplication::translate("MainWindow", "M3", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
