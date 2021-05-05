#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QLabel>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // setting Background...
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/img/imgs/BG.png").scaled(this->size(),
                     Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Setting Start Text...
    ui->StartText->setGeometry(250,10,100,15);
    // Setting Start button...
    Startbtn = new QPushButton(this);
    Startbtn->setGeometry(230,50,140,100);
    Startbtn->setIcon(QIcon(":/img/imgs/main.png"));
    Startbtn->setIconSize(Startbtn->size());
    Startbtn->setStyleSheet("border:none");
    // Setting Level Text...
    ui->Level->setGeometry(200,150,200,15);
    // Setting Level button...
    LV1btn = new QPushButton(this);
    LV2btn = new QPushButton(this);
    LV1btn->setGeometry(100,180,100,30);
    LV2btn->setGeometry(400,180,100,30);
    LV1btn->setText("LV1");
    LV2btn->setText("LV2");
    //Setting Exit button...
    Exitbtn = new QPushButton(this);
    Exitbtn->setGeometry(250,230,100,30);
    Exitbtn->setText("EXIT");
    // Setting Connection...
    connect(Exitbtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(Startbtn,SIGNAL(clicked()),this,SLOT(StartbuttonClick()));
    connect(LV1btn,SIGNAL(clicked()),this,SLOT(LV1buttonClick()));
    connect(LV2btn,SIGNAL(clicked()),this,SLOT(LV2buttonClick()));

/* Label picture example...
    QPixmap pix(":/img/imgs/mario.png");
    ui->testlabel->setPixmap(pix.scaled(
        ui->testlabel->width(),ui->testlabel->height()
        ,Qt::KeepAspectRatio));
*/
}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::LV1buttonClick()
{
    lv1->show();
}

void MainWindow::LV2buttonClick()
{
    LV2 *lv2 = new LV2();
    lv2->show();
}

void MainWindow::StartbuttonClick()  //example1-4
{
    // Startbtn->setGeometry(Startbtn->x()+1,50,50,50);
    lv1->show();
}
