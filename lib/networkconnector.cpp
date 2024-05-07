#include "networkconnector.h"

NetworkConnector::NetworkConnector(QObject *parent) : QObject(parent),
    m_socket(new QTcpSocket(this))
{
    connect(m_socket, &QTcpSocket::connected, this, &NetworkConnector::onConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &NetworkConnector::onReadyRead);
    m_logger = new FileLogger(this);
}

NetworkConnector::~NetworkConnector()
{
    if (m_socket)
    {
        m_socket->deleteLater();
    }

    if (m_server)
    {
        m_server->close();
        m_server->deleteLater();
    }
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
}

// Получаем сообщение от сервера
void NetworkConnector::onReadyRead()
{
    QString message = m_socket->readAll();
    qDebug() << "Message from server:" << message;
    emit messageReceived(message);
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
        // Читаем сообщение от клиента
        QString message = QString::fromUtf8(clientSocket->readAll());
        qDebug() << "Message from client:" << message;

        // Выполняем вычисление выражения
        QJSValue result = engine.evaluate(message);

        // Проверяем на наличие ошибок
        QString resultString;
        if (result.isError()) {
            qDebug() << "Error evaluating expression:" << result.toString();
            resultString = "ERROR";
            sendResponseToClient(clientSocket, "ERROR");
        } else {
            // Проверяем, является ли результат конечным числом
            double numericResult = result.toNumber();
            if (std::isfinite(numericResult)) {
                qDebug() << "Expression result:" << numericResult;
                resultString = QString::number(numericResult);
                QString response = processMessage(result.toString());
                sendResponseToClient(clientSocket, response);
            } else {
                qDebug() << "Expression result: inf";
                resultString = "ERROR";
                sendResponseToClient(clientSocket, "ERROR");
            }
        }

        // Записываем данные в файл с помощью FileLogger
        m_logger->logMessage(message, resultString);
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

QTcpSocket* NetworkConnector::getSocket() const
{
    return m_socket;
}
