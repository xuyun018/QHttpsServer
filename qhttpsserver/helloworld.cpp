#include "helloworld.h"
#include "qhttpserver.h"
#include "qhttprequest.h"
#include "qhttpresponse.h"
#include "qhttpserverfwd.h"
#include <QDebug>

/// HelloWorld

HelloWorld::HelloWorld()
{
    QHttpServer *server = new QHttpServer(this);

    connect(server, &QHttpServer::newRequest,
            this, &HelloWorld::handleRequest);

    //server->listen(QHostAddress::Any, 443,
    //               "./key/server/server-cert.pem", "./key/server/server-key.pem");
    server->listen(QHostAddress::Any, 443,
                   "server-cert.pem", "server-key.pem");

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
    resp->setHeader("Content-Length", QString::number(body.size()));
    resp->writeHead(200);
    resp->end(body);
}
