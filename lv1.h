#ifndef LV1_H
#define LV1_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>


namespace Ui {
class LV1;
}

class LV1 : public QMainWindow
{
    Q_OBJECT
signals:
    void RE();

public:
    explicit LV1(QWidget *parent = nullptr);
    ~LV1();
    void keyPressEvent(QKeyEvent *event);
    bool CanPushLeft();
    bool CanPushRight();
    bool CanPushUp();
    bool CanPushDown();
    bool Succeed();


private slots:
    void RestartbuttonClick();
    void NextbuttonClick();
    void MenubuttonClick();

private:
    Ui::LV1 *ui;
    int steps;

};

#endif // LV1_H
