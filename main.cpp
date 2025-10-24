#include <QApplication>
#include "src/core/application.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Application app;
    return a.exec();
}
