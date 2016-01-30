#include <cmath>

#include "dds.h"

DDS::DDS(double fRef)
{
    this->frequencyReference = fRef;
}

double DDS::getFrequencyReference() const
{
    return frequencyReference;
}

void DDS::setFrequencyReference(double value)
{
    frequencyReference = value;
}

double DDS::getOutputFrequency() const
{
    return outputFrequency;
}

void DDS::setOutputFrequency(double value)
{
    outputFrequency = value;
}

outputCodeFrequency DDS::frequencyToCode()
{
    outputCodeFrequency outputCode;

    qint64 code;

    if (this->outputFrequency >= 0)
    {
        code = (qint64) fabs(pow(2, 48) * (this->outputFrequency/this->frequencyReference));
    }
    else
    {
        code = (qint64) fabs(pow(2, 48) * (fabs(this->outputFrequency)/this->frequencyReference));
        code = ~code + 1;
    }

    outputCode.codeH = (qint16) ((code >> 32) & 0xffff);
    outputCode.codeM = (qint16) ((code >> 16) & 0xffff);
    outputCode.codeL = (qint16) (code & 0xffff);

    return outputCode;
}

qint64 DDS::codeToFrequency(qint16 codeDDSH, qint16 codeDDSM, qint16 codeDDSL)
{
    qint64 codeOutputFrequency = (qint64)(codeDDSH * pow(2, 32) + codeDDSM * pow(2, 16) + codeDDSL);
    return (double)(codeOutputFrequency * this->frequencyReference / pow(2, 48));
}



