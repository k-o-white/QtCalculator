#include <QApplication>
#include "calculator.h"
#include "./ui_caller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.lineEdit = caller.lineEdit;
    window.resize(480, 640);
    window.show();
    return app.exec();
}
