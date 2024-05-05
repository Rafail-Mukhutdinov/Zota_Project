#ifndef NETWORKCONNECTOR_H
#define NETWORKCONNECTOR_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QCoreApplication>
#include <QDebug>

class NetworkConnector : public QObject
{
    Q_OBJECT

public:
    explicit NetworkConnector(QObject *parent = nullptr);
    QAbstractSocket::SocketState socketState() const;
    void sendMessage(const QString &message);
    void connectToServer(const QHostAddress &address, quint16 port);
    void startServer(const QHostAddress &address, quint16 port);
    void disconnectFromServer();

private:
    void onClientMessageReceived();
    void sendResponseToClient(QTcpSocket* clientSocket, const QString &response);
    QString processMessage(const QString &message);

private slots:
    void onNewConnection();
    void onClientDisconnected();
    void onConnected();
    void onReadyRead();

private:
    QTcpSocket *m_socket;
    QTcpServer *m_server = nullptr;
};

#endif // NETWORKCONNECTOR_H
