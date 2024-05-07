#include "filelogger.h"

FileLogger::FileLogger(QObject *parent) : QObject(parent)
{
    // Открываем файл для записи (можно указать свой путь и имя файла)
    m_logFile.setFileName("expression_log.txt");
    m_logFile.open(QIODevice::WriteOnly | QIODevice::Append);
}

void FileLogger::logMessage(const QString &message, const QString &result)
{
    // Получаем текущее время
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    // Записываем данные в файл
    QTextStream stream(&m_logFile);
    stream << timestamp << " | Message: " << message << " | Result: " << result << "\n";
}

FileLogger::~FileLogger()
{
    if (m_logFile.isOpen()) {
        m_logFile.close();
    }
}
