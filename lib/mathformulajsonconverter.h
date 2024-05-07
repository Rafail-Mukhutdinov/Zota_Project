#ifndef MATHFORMULAJSONCONVERTER_H
#define MATHFORMULAJSONCONVERTER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

class MathFormulaJsonConverter
{
public:
    MathFormulaJsonConverter();
    static QJsonObject formulaToJson(const QString &formula);
    static QString jsonToFormula(const QJsonObject &json);
};

#endif // MATHFORMULAJSONCONVERTER_H
