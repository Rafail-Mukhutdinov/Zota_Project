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


QString StringProcessor::removeLeadingZeroAfterOperator(const QString &expression)
{

    QRegularExpression regex("^0+(\\d)|([+\\-*/])0+(\\d)");

    QString modifiedExpression = expression;
    QRegularExpressionMatchIterator it = regex.globalMatch(expression);
    while (it.hasNext())
    {
        QRegularExpressionMatch match = it.next();

        if (match.captured(1).length() > 0) {
            modifiedExpression.replace(match.captured(0), match.captured(1));
        } else {
            modifiedExpression.replace(match.captured(0), match.captured(2) + match.captured(3));
        }
    }

    return modifiedExpression;
}


QString StringProcessor::replaceLastOperator(const QString &expression, QChar newOperator)
{
    QString modifiedExpression = expression;

    if (!modifiedExpression.isEmpty() && isOperator(modifiedExpression[modifiedExpression.length() - 1]))
    {
        modifiedExpression[modifiedExpression.length() - 1] = newOperator;
    }
    else
    {
        modifiedExpression += newOperator;
    }

    return modifiedExpression;
}

bool StringProcessor::isOperator(QChar ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}



