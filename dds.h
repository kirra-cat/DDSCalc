#ifndef DDS_H
#define DDS_H

#include <QObject>
#include <QTypeInfo>

typedef struct
{
    qint16 codeH;
    qint16 codeM;
    qint16 codeL;
} outputCodeFrequency;

class DDS
{
public:
    DDS(double fRef);

    double getFrequencyReference() const;
    void setFrequencyReference(double value);

    double getOutputFrequency() const;
    void setOutputFrequency(double value);

    outputCodeFrequency frequencyToCode();
    qint64 codeToFrequency(qint16 codeDDSH, qint16 codeDDSM, qint16 codeDDSL);
private:
    double frequencyReference;
    double outputFrequency;
};

#endif // DDS_H
