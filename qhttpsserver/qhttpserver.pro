#-------------------------------------------------
#
# Project created by QtCreator 2017-03-16T15:03:00
#
#-------------------------------------------------

QT       += core network
QT       -= gui

TARGET = qhttpserver
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
CONFIG += debug_and_release

QHTTPSERVER_BASE = .

INCLUDEPATH += $$QHTTPSERVER_BASE/http-parser

PRIVATE_HEADERS += $$QHTTPSERVER_BASE/http-parser/http_parser.h qhttpconnection.h
PUBLIC_HEADERS += qhttpserver.h qhttprequest.h qhttpresponse.h qhttpserverapi.h qhttpserverfwd.h helloworld.h

HEADERS = $$PRIVATE_HEADERS $$PUBLIC_HEADERS \
    qsslserver.h
SOURCES = *.cpp $$QHTTPSERVER_BASE/http-parser/http_parser.c
