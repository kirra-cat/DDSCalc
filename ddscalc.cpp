#include "ddscalc.h"
#include "ui_ddscalc.h"

DDSCalc::DDSCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DDSCalc)
{
    ui->setupUi(this);
}

DDSCalc::~DDSCalc()
{
    delete ui;
}
