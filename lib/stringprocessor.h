#ifndef STRINGPROCESSOR_H
#define STRINGPROCESSOR_H

#include <QString>
#include <QRegularExpression>

class StringProcessor
{
public:

    QString removeLastOperator(const QString &expression);
    QString removeLeadingZeroAfterOperator(const QString &expression);
    QString replaceLastOperator(const QString &expression, QChar newOperator);

private:

    bool isOperator(QChar ch);
};

#endif // STRINGPROCESSOR_H
