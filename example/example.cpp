#include <QtCore>
#include <QtGui>

#include "AppWidget.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv, 1);

    new AppWidget();

    return app.exec();
}
