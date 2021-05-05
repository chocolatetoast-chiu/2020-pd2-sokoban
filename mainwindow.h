#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>  //example1-0
#include "lv1.h"
#include "lv2.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void StartbuttonClick(); //example 1-3
    void LV1buttonClick();
    void LV2buttonClick();


private:
    Ui::MainWindow *ui;
    QPushButton *Startbtn;
    QPushButton *Exitbtn;
    QPushButton *LV1btn;
    QPushButton *LV2btn;
    LV1 *lv1 = new LV1();


};



#endif // MAINWINDOW_H
