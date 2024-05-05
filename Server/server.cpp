#include <QCoreApplication>
#include "../lib/networkconnector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetworkConnector net;
    net.startServer(QHostAddress::Any, 1234);
    return a.exec();
}
