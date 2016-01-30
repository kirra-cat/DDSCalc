#ifndef DDSCALC_H
#define DDSCALC_H

#include <QMainWindow>

namespace Ui {
class DDSCalc;
}

class DDSCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit DDSCalc(QWidget *parent = 0);
    ~DDSCalc();

private:
    Ui::DDSCalc *ui;
};

#endif // DDSCALC_H
