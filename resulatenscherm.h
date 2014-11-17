#ifndef RESULATENSCHERM_H
#define RESULATENSCHERM_H

#include <QMainWindow>

namespace Ui {
class ResulatenScherm;
}

class ResulatenScherm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResulatenScherm(QWidget *parent = 0);
    ~ResulatenScherm();

private:
    Ui::ResulatenScherm *ui;
};

#endif // RESULATENSCHERM_H
