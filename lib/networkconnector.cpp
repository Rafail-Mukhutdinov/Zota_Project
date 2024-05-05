#include "networkconnector.h"

NetworkConnector::NetworkConnector(QObject *parent) : QObject(parent),
    m_socket(new QTcpSocket(this))
{
    connect(m_socket, &QTcpSocket::connected, this, &NetworkConnector::onConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &NetworkConnector::onReadyRead);
}

void NetworkConnector::startServer(const QHostAddress &address, quint16 port)
{
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &NetworkConnector::onNewConnection);

    if (!m_server->listen(address, port))
    {
        qDebug() << "Server could not start!";
    } else
    {
        qDebug() << "Server started!";
    }
}

void NetworkConnector::connectToServer(const QHostAddress &address, quint16 port)
{
    m_socket->connectToHost(address, port);
}

void NetworkConnector::onNewConnection()
{
    QTcpSocket *clientSocket = m_server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::disconnected, this, &NetworkConnector::onClientDisconnected);
    connect(clientSocket, &QTcpSocket::readyRead, this, &NetworkConnector::onClientMessageReceived);
    clientSocket->write("Welcome to the Server!\n");
    clientSocket->flush();

    qDebug() << "Client connected:" << clientSocket->peerAddress().toString() << "Port:" << clientSocket->peerPort();
}


void NetworkConnector::onClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket)
    {
        qDebug() << "Client disconnected:" << clientSocket->peerAddress().toString() << "Port:" << clientSocket->peerPort();
        clientSocket->deleteLater();
    }
}

void NetworkConnector::onConnected()
{
    qDebug() << "Connected to server!";
    m_socket->write("Hello, server!\n");
}

void NetworkConnector::onReadyRead()
{
    qDebug() << "Message from server:" << m_socket->readAll();
}

void NetworkConnector::disconnectFromServer()
{
    if (m_socket->state() == QAbstractSocket::ConnectedState)
    {
        m_socket->disconnectFromHost();
    }

}

QAbstractSocket::SocketState NetworkConnector::socketState() const
{
    return m_socket->state();
}


void NetworkConnector::sendMessage(const QString &message)
{
    if (m_socket && m_socket->state() == QAbstractSocket::ConnectedState)
    {
        m_socket->write(message.toUtf8());
    }
}

void NetworkConnector::onClientMessageReceived()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket && clientSocket->bytesAvailable())
    {

        QString message = QString::fromUtf8(clientSocket->readAll());
         qDebug() << "Message from client:" << message;
        QString response = processMessage(message);
        sendResponseToClient(clientSocket, response);
    }

}

void NetworkConnector::sendResponseToClient(QTcpSocket* clientSocket, const QString &response)
{
    if (clientSocket && clientSocket->state() == QAbstractSocket::ConnectedState)
    {
        clientSocket->write(response.toUtf8());
        clientSocket->flush();
    }
}

QString NetworkConnector::processMessage(const QString &message)
{
    // Здесь логика обработки сообщения

    return message;
}
