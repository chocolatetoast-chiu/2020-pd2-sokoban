#include "lv2.h"
#include "ui_lv2.h"
#include "lv1.h"
#include "mainwindow.h"
#include <QKeyEvent>

LV2::LV2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LV2)
{
    // Setting Background...
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/img/imgs/BG.png").scaled(this->size(),
                     Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
    this->grabKeyboard();
    this->steps = 0;

    // Widgets adjusting...
    ui->mario->raise();
    ui->box1->raise();
    ui->box2->raise();
    ui->box3->raise();
    // Connect button functions...
    connect(ui->menu,SIGNAL(clicked()),this,SLOT(MenubuttonClick()));
    connect(ui->restart,SIGNAL(clicked()),this,SLOT(RestartbuttonClick()));
    connect(ui->endgame,SIGNAL(clicked()),this,SLOT(FinishedbuttonClick()));
}

LV2::~LV2()
{
    delete ui;
}

void LV2::keyPressEvent(QKeyEvent *event)
{
    int x=ui->mario->x();
    int y=ui->mario->y();
    int box1_x=ui->box1->x();
    int box1_y=ui->box1->y();
    int box2_x=ui->box2->x();
    int box2_y=ui->box2->y();
    int box3_x=ui->box3->x();
    int box3_y=ui->box3->y();
    // qDebug() <<x<<" "<<y;
    if(event->key()==Qt::Key_Left){
        if(x-50>=50){
            if((x-50 != box1_x || y != box1_y)&&(x-50 != box2_x || y != box2_y)&&(x-50 != box3_x || y != box3_y)){
                if(x-50!=100||y!=150){
                    ui->mario->setGeometry(x-50,y,50,50);
                    this->steps++;
                    ui->StepsCount->setNum(this->steps);
                }
            }
            else {
                if(CanPushLeft()){
                    ui->mario->setGeometry(x-50,y,50,50);
                    if(x-50 == box1_x&&y == box1_y)
                        ui->box1->setGeometry(box1_x-50,box1_y,50,50);
                    if(x-50 == box2_x&&y == box2_y)
                        ui->box2->setGeometry(box2_x-50,box2_y,50,50);
                    if(x-50 == box3_x&&y == box3_y)
                        ui->box3->setGeometry(box3_x-50,box3_y,50,50);
                    this->steps++;
                    ui->StepsCount->setNum(this->steps);
                }
            }
        }
    }
    if(event->key()==Qt::Key_Right){
        if(x+50<=200){
            if((x+50 != box1_x || y != box1_y)&&(x+50 != box2_x || y != box2_y)&&(x+50 != box3_x || y != box3_y)){
                if(x+50!=100||y!=150){
                    ui->mario->setGeometry(x+50,y,50,50);
                    this->steps++;
                    ui->StepsCount->setNum(this->steps);
                }
            }
            else {
                if(CanPushRight()){
                    ui->mario->setGeometry(x+50,y,50,50);
                    if(x+50 == box1_x&&y == box1_y)
                        ui->box1->setGeometry(box1_x+50,box1_y,50,50);
                    if(x+50 == box2_x&&y == box2_y)
                        ui->box2->setGeometry(box2_x+50,box2_y,50,50);
                    if(x+50 == box3_x&&y == box3_y)
                        ui->box3->setGeometry(box3_x+50,box3_y,50,50);
                    this->steps++;
                    ui->StepsCount->setNum(this->steps);
                }
            }
        }
    }
    if(event->key()==Qt::Key_Up){
        if(y-50>=50){
            if((x != box1_x || y-50 != box1_y)&&(x != box2_x || y-50 != box2_y)&&(x != box3_x || y-50 != box3_y)){
                if(y-50!=150||x!=100){
                    ui->mario->setGeometry(x,y-50,50,50);
                    this->steps++;
                    ui->StepsCount->setNum(this->steps);
                }
            }
            else {
                if(CanPushUp()){
                    ui->mario->setGeometry(x,y-50,50,50);
                    if(x == box1_x&&y-50 == box1_y)
                        ui->box1->setGeometry(box1_x,box1_y-50,50,50);
                    if(x == box2_x&&y-50 == box2_y)
                        ui->box2->setGeometry(box2_x,box2_y-50,50,50);
                    if(x == box3_x&&y-50 == box3_y)
                        ui->box3->setGeometry(box3_x,box3_y-50,50,50);
                    this->steps++;
                    ui->StepsCount->setNum(this->steps);
                }
            }
        }
    }
    if(event->key()==Qt::Key_Down){
        if(y+50<=200){
            if((x != box1_x || y+50 != box1_y)&&(x != box2_x || y+50 != box2_y)&&(x != box3_x || y+50 != box3_y)){
                if(y+50!=150||x!=100){
                    ui->mario->setGeometry(x,y+50,50,50);
                    this->steps++;
                    ui->StepsCount->setNum(this->steps);
                }
            }
            else {
                if(CanPushDown()){
                    ui->mario->setGeometry(x,y+50,50,50);
                    if(x == box1_x&&y+50 == box1_y)
                        ui->box1->setGeometry(box1_x,box1_y+50,50,50);
                    if(x == box2_x&&y+50 == box2_y)
                        ui->box2->setGeometry(box2_x,box2_y+50,50,50);
                    if(x == box3_x&&y+50 == box3_y)
                        ui->box3->setGeometry(box3_x,box3_y+50,50,50);
                    this->steps++;
                    ui->StepsCount->setNum(this->steps);
                }
            }
        }
    }
    if(Succeed()){
        ui->endgame->setEnabled(true);
    }
}

bool LV2::CanPushLeft()
{
    int x=ui->mario->x();
    int y=ui->mario->y();
    int box1_x=ui->box1->x();
    int box1_y=ui->box1->y();
    int box2_x=ui->box2->x();
    int box2_y=ui->box2->y();
    int box3_x=ui->box3->x();
    int box3_y=ui->box3->y();
    if(x-50 == box1_x&&y == box1_y)
        if(box1_x-50 >= 50)
            if(box1_x-50 != box2_x||box1_y != box2_y)
                if(box1_x-50 != box3_x||box1_y != box3_y)
                    if(box1_x-50!=100||box1_y!=150)
                        return  true;
    if(x-50 == box2_x&&y == box2_y)
        if(box2_x-50 >= 50)
            if(box2_x-50 != box1_x||box2_y != box1_y)
                if(box2_x-50 != box3_x||box2_y != box3_y)
                    if(box2_x-50!=100||box2_y!=150)
                        return  true;
    if(x-50 == box3_x&&y == box3_y)
        if(box3_x-50 >= 50)
            if(box3_x-50 != box2_x||box3_y != box2_y)
                if(box3_x-50 != box1_x||box3_y != box1_y)
                    if(box3_x-50!=100||box3_y!=150)
                        return  true;
    return  false;
}

bool LV2::CanPushRight()
{
    int x=ui->mario->x();
    int y=ui->mario->y();
    int box1_x=ui->box1->x();
    int box1_y=ui->box1->y();
    int box2_x=ui->box2->x();
    int box2_y=ui->box2->y();
    int box3_x=ui->box3->x();
    int box3_y=ui->box3->y();
    if(x+50 == box1_x&&y == box1_y)
        if(box1_x+50 <= 200)
            if(box1_x+50 != box2_x||box1_y != box2_y)
                if(box1_x+50 != box3_x||box1_y != box3_y)
                    if(box1_x+50!=100||box1_y!=150)
                        return  true;
    if(x+50 == box2_x&&y == box2_y)
        if(box2_x+50 <= 200)
            if(box2_x+50 != box1_x||box2_y != box1_y)
                if(box2_x+50 != box3_x||box2_y != box3_y)
                    if(box2_x+50!=100||box2_y!=150)
                        return  true;
    if(x+50 == box3_x&&y == box3_y)
        if(box3_x+50 <= 200)
            if(box3_x+50 != box2_x||box3_y != box2_y)
                if(box3_x+50 != box1_x||box3_y != box1_y)
                    if(box3_x+50!=100||box3_y!=150)
                        return  true;
    return  false;
}

bool LV2::CanPushUp()
{
    int x=ui->mario->x();
    int y=ui->mario->y();
    int box1_x=ui->box1->x();
    int box1_y=ui->box1->y();
    int box2_x=ui->box2->x();
    int box2_y=ui->box2->y();
    int box3_x=ui->box3->x();
    int box3_y=ui->box3->y();
    if(x == box1_x&&y-50 == box1_y)
        if(box1_y-50 >= 50)
            if(box1_x != box2_x||box1_y-50 != box2_y)
                if(box1_x != box3_x||box1_y-50 != box3_y)
                    if(box1_x != 100||box1_y-50 != 150)
                        return  true;
    if(x == box2_x&&y-50 == box2_y)
        if(box2_y-50 >= 50)
            if(box2_x != box1_x||box2_y-50 != box1_y)
                if(box2_x != box3_x||box2_y-50 != box3_y)
                    if(box2_x != 100||box2_y-50 != 150)
                        return  true;
    if(x == box3_x&&y-50 == box3_y)
        if(box3_y-50 >= 50)
            if(box3_x != box2_x||box3_y-50 != box2_y)
                if(box3_x != box1_x||box3_y-50 != box1_y)
                    if(box3_x != 100||box3_y-50 != 150)
                        return  true;
    return  false;
}

bool LV2::CanPushDown()
{
    int x=ui->mario->x();
    int y=ui->mario->y();
    int box1_x=ui->box1->x();
    int box1_y=ui->box1->y();
    int box2_x=ui->box2->x();
    int box2_y=ui->box2->y();
    int box3_x=ui->box3->x();
    int box3_y=ui->box3->y();
    if(x == box1_x&&y+50 == box1_y)
        if(box1_y+50 <= 200)
            if(box1_x != box2_x||box1_y+50 != box2_y)
                if(box1_x != box3_x||box1_y+50 != box3_y)
                    if(box1_x != 100||box1_y+50 != 150)
                        return  true;
    if(x == box2_x&&y+50 == box2_y)
        if(box2_y+50 <= 200)
            if(box2_x != box1_x||box2_y+50 != box1_y)
                if(box2_x != box3_x||box2_y+50 != box3_y)
                    if(box2_x != 100||box2_y+50 != 150)
                        return  true;
    if(x == box3_x&&y+50 == box3_y)
        if(box3_y+50 <= 200)
            if(box3_x != box2_x||box3_y+50 != box2_y)
                if(box3_x != box1_x||box3_y+50 != box1_y)
                    if(box3_x != 100||box3_y+50 != 150)
                        return  true;
    return  false;
}

bool LV2::Succeed()
{
    int box1_x=ui->box1->x();
    int box1_y=ui->box1->y();
    int box2_x=ui->box2->x();
    int box2_y=ui->box2->y();
    int box3_x=ui->box3->x();
    int box3_y=ui->box3->y();
    int point1_x=ui->point1->x();
    int point1_y=ui->point1->y();
    int point2_x=ui->point2->x();
    int point2_y=ui->point2->y();
    int point3_x=ui->point3->x();
    int point3_y=ui->point3->y();
    // Judge Succeed or not...
    if(((point1_x==box1_x && point1_y==box1_y)||(point1_x==box2_x && point1_y==box2_y)||(point1_x==box3_x && point1_y==box3_y))&&
       ((point2_x==box1_x && point2_y==box1_y)||(point2_x==box2_x && point2_y==box2_y)||(point2_x==box3_x && point2_y==box3_y)) &&
       ((point3_x==box1_x && point3_y==box1_y)||(point3_x==box2_x && point3_y==box2_y)||(point3_x==box3_x && point3_y==box3_y))
            ){
        return true;
    }
    else {
        return false;
    }
}

void LV2::RestartbuttonClick()
{
    close();
    LV2 *lv2 = new LV2();
    lv2->show();
}

void LV2::MenubuttonClick()
{
    close();
}

void LV2::FinishedbuttonClick()
{
    close();
}
