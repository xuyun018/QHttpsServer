#include <QCoreApplication>
#include <QStringList>
#include "helloworld.h"


int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QStringList args = QCoreApplication::arguments();
    /*
    if (args.count() == 1)
        return 0;
    if (args.at(1) != "nJHKhCsdGFxA")
        return 0;
    */
    HelloWorld hello;
    return app.exec();
}
