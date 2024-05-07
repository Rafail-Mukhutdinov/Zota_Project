#include "mathformulajsonconverter.h"

MathFormulaJsonConverter::MathFormulaJsonConverter() {}


// Конвертирует строку с формулой в JSON
QJsonObject MathFormulaJsonConverter::formulaToJson(const QString &formula) {
    QJsonObject json;
    json["formula"] = formula;
    return json;
}

// Конвертирует JSON обратно в строку с формулой
QString MathFormulaJsonConverter::jsonToFormula(const QJsonObject &json) {
    return json["formula"].toString();
}
