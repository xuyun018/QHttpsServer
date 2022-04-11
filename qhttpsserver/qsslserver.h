#ifndef QSSLSERVER_H
#define QSSLSERVER_H

#include <QTcpServer>
#include <QSslConfiguration>

class QSslServer : public QTcpServer
{
public:
    QSslServer(QObject *parent = 0);

    void setSslConfiguration(const QSslConfiguration& config);

protected:
    virtual void incomingConnection(int handle);

private:
    QSslConfiguration m_sslConfiguration;
};

#endif // QSSLSERVER_H
