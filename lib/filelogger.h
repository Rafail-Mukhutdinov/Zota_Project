#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class FileLogger : public QObject
{
    Q_OBJECT
public:
    explicit FileLogger(QObject *parent = nullptr);
    ~FileLogger();
    void logMessage(const QString &message, const QString &result);

private:
    QFile m_logFile;
};

#endif // FILELOGGER_H
