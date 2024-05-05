#include "stringprocessor.h"


QString StringProcessor::removeLastOperator(const QString &expression)
{

    if (expression.isEmpty()) return expression;

    QChar lastChar = expression[expression.length() - 1];
    if (lastChar == '+' || lastChar == '*' || lastChar == '/' || lastChar == '-')
    {
        return expression.left(expression.length() - 1);
    }
    return expression;
}
