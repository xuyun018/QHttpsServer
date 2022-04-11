#include "qsslserver.h"
#include <QSslSocket>

QSslServer::QSslServer(QObject *parent)
    : QTcpServer(parent)
{

}

void QSslServer::setSslConfiguration(const QSslConfiguration& config)
{
    m_sslConfiguration = config;
}

void QSslServer::incomingConnection(int socketDescriptor)
{
    qDebug("QSslServer::incomingConnection(%i)", socketDescriptor);

    QSslSocket *socket = new QSslSocket(this);
    socket->setProperty("isSslSocket", true);
    socket->setSocketDescriptor(socketDescriptor);
    socket->setSslConfiguration(m_sslConfiguration);
    //socket->startServerEncryption();
    addPendingConnection((QTcpSocket *)socket);
}
