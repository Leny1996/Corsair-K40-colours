#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

extern "C" {
#include <unistd.h>
#include <getopt.h>
#include <libusb-1.0/libusb.h>
}


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

    void on_btnCancel_clicked();
    void on_btnUpdate_clicked();

public:

protected:
    void printStatus();


    };
#endif // MAINWINDOW_H
