#ifndef LV2_H
#define LV2_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class LV2;
}

class LV2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LV2(QWidget *parent = nullptr);
    ~LV2();
    void keyPressEvent(QKeyEvent *event);
    bool CanPushLeft();
    bool CanPushRight();
    bool CanPushUp();
    bool CanPushDown();
    bool Succeed();

private slots:
    void RestartbuttonClick();
    void FinishedbuttonClick();
    void MenubuttonClick();

private:
    Ui::LV2 *ui;
    int steps;
};

#endif // LV2_H
