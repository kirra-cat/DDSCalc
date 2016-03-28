#include "ddscalc.h"
#include "ui_ddscalc.h"
#include "dds.h"

#include <QClipboard>

DDSCalc::DDSCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DDSCalc)
{
    ui->setupUi(this);

    QObject::connect(ui->lineEditFrequencyReference, SIGNAL(textEdited(QString)),
                     this, SLOT(updateFrequencyToCodeDDS()));

    QObject::connect(ui->lineEditFrequencyOutput, SIGNAL(textEdited(QString)),
                     this, SLOT(updateFrequencyToCodeDDS()));

    QObject::connect(ui->checkBoxAdd0x, SIGNAL(clicked(bool)),
                     this, SLOT(updateFrequencyToCodeDDS()));

    QObject::connect(ui->checkBoxUpperCase, SIGNAL(clicked(bool)),
                     this, SLOT(updateFrequencyToCodeDDS()));

    QObject::connect(ui->lineEditDDSCodeH, SIGNAL(selectionChanged()),
                     this, SLOT(copyToClipboard()));
    QObject::connect(ui->lineEditDDSCodeH, SIGNAL(textEdited(QString)),
                     this, SLOT(updateCodeToFrequencyDDS()));

    QObject::connect(ui->lineEditDDSCodeM, SIGNAL(selectionChanged()),
                     this, SLOT(copyToClipboard()));
    QObject::connect(ui->lineEditDDSCodeM, SIGNAL(textEdited(QString)),
                     this, SLOT(updateCodeToFrequencyDDS()));

    QObject::connect(ui->lineEditDDSCodeL, SIGNAL(selectionChanged()),
                     this, SLOT(copyToClipboard()));
    QObject::connect(ui->lineEditDDSCodeL, SIGNAL(textEdited(QString)),
                     this, SLOT(updateCodeToFrequencyDDS()));
}

void DDSCalc::updateFrequencyToCodeDDS()
{
    if (ui->lineEditFrequencyReference->text().length() != 0 &&
        ui->lineEditFrequencyOutput->text().length() != 0)
    {
        DDS *dds = new DDS(ui->lineEditFrequencyReference->text().toDouble());
        dds->setOutputFrequency(ui->lineEditFrequencyOutput->text().toDouble());

        QString templateOutputString;
        templateOutputString = (ui->checkBoxAdd0x->checkState() == Qt::Checked) ?
                    templateOutputString.append("0x") : templateOutputString.append("");

        templateOutputString = (ui->checkBoxUpperCase->checkState() == Qt::Checked) ?
                    templateOutputString.append("%1.4X") : templateOutputString.append("%1.4x");

        ui->lineEditDDSCodeH->setText(QString().sprintf(templateOutputString.toStdString().c_str(),
                                                        dds->frequencyToCode().codeH));

        ui->lineEditDDSCodeM->setText(QString().sprintf(templateOutputString.toStdString().c_str(),
                                                        dds->frequencyToCode().codeM));

        ui->lineEditDDSCodeL->setText(QString().sprintf(templateOutputString.toStdString().c_str(),
                                                        dds->frequencyToCode().codeL));
    }
}

void DDSCalc::updateCodeToFrequencyDDS()
{
    if (ui->lineEditDDSCodeH->text().length() != 0 &&
        ui->lineEditDDSCodeM->text().length() != 0 &&
        ui->lineEditDDSCodeL->text().length() != 0 &&
        ui->lineEditFrequencyReference->text().length() != 0)
    {
        DDS *dds = new DDS(ui->lineEditFrequencyReference->text().toDouble());

        ui->lineEditFrequencyOutput->setText(
            QString::number(
                dds->codeToFrequency((qint16) ui->lineEditDDSCodeH->text().toInt(),
                                     (qint16) ui->lineEditDDSCodeM->text().toInt(),
                                     (qint16) ui->lineEditDDSCodeL->text().toInt())
                           )
                    );
    }
}

void DDSCalc::copyToClipboard()
{
    QLineEdit *edit = static_cast<QLineEdit*>(sender());
    QApplication::clipboard()->setText(edit->text());
}

DDSCalc::~DDSCalc()
{
    delete ui;
}
