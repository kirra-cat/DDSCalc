#ifndef DDSCALC_H
#define DDSCALC_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class DDSCalc;
}

class DDSCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit DDSCalc(QWidget *parent = 0);
    ~DDSCalc();

public slots:
    void updateFrequencyToCodeDDS();

    void updateCodeToFrequencyDDS();

    void copyToClipboard();


private:
    Ui::DDSCalc *ui;
};

#endif // DDSCALC_H
