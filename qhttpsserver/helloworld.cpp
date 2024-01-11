#include "helloworld.h"
#include "qhttpserver.h"
#include "qhttprequest.h"
#include "qhttpresponse.h"
#include "qhttpserverfwd.h"
#include <QDebug>

#include <QFile>

/// HelloWorld

HelloWorld::HelloWorld()
{
    QHttpServer *server = new QHttpServer(this);

    connect(server, &QHttpServer::newRequest,
            this, &HelloWorld::handleRequest);
    connect(server, &QHttpServer::socket1Disconnected,
            this, &HelloWorld::handleDisconnect);

    //server->listen(QHostAddress::Any, 443,
    //               "./key/server/server-cert.pem", "./key/server/server-key.pem");
    //server->listen(QHostAddress::Any, 443,
    //               "server-cert.pem", "server-key.pem");
    // 这个好,别的都不好或者不行
    server->listen(QHostAddress::Any, 443,
                   "cert.pem", "key.pem");
    //server->listen(QHostAddress::Any, 443,
    //               "server.crt", "server.key");
    //server->listen(QHostAddress::Any, 80,
    //               "", "");

    qDebug() << "listen port 443";
}

void HelloWorld::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
    Q_UNUSED(req);

    QString path = req->path();
    qDebug() << "path: " << path;
    QByteArray body;
    if (path == "/data/unknownSources")
        body = "{\"status\":\"0\",\"message\":\"ok\"}";
    else
        body = "Hello World";

    QString filename = "C:\\Temp\\2.txt";
    QFile *downloadedFile;
    downloadedFile = new QFile(filename);
    if (downloadedFile->open(QIODevice::ReadOnly))
    {
        body = downloadedFile->read(downloadedFile->size());
        //downloadedFile->read(body.data_ptr()->data(),body.size());

        downloadedFile->close();
        delete downloadedFile;
    }

    resp->setHeader("Content-Length", QString::number(body.size()));
    resp->writeHead(200);
    resp->end(body);
}
void HelloWorld::handleDisconnect(QHttpConnection *conn)
{
    qDebug() << "handleDisconnect";
}
