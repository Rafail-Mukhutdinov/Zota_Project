#ifndef NETWORKCONNECTOR_H
#define NETWORKCONNECTOR_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QJSEngine>
#include "filelogger.h"
#include "mathformulajsonconverter.h"

class NetworkConnector : public QObject
{
    Q_OBJECT

public:
    explicit NetworkConnector(QObject *parent = nullptr);
    ~NetworkConnector();
    QAbstractSocket::SocketState socketState() const;
    void sendMessage(const QString &message);
    void connectToServer(const QHostAddress &address, quint16 port);
    void startServer(const QHostAddress &address, quint16 port);
    void disconnectFromServer();
    QTcpSocket* getSocket() const;


private:
    void sendResponseToClient(QTcpSocket* clientSocket, const QString &response);
    QString processMessage(const QString &message);

private slots:
    void onNewConnection();
    void onClientDisconnected();
    void onConnected();
    void onReadyRead();
    void onClientMessageReceived();

signals:
    void messageReceived(const QString &message);

private:
    QTcpSocket *m_socket;
    QTcpServer *m_server = nullptr;
    QJSEngine engine;
    FileLogger *m_logger;
    MathFormulaJsonConverter matJson;
};

#endif // NETWORKCONNECTOR_H
