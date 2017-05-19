#include "passworddialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PasswordDialog w;
    w.show();

    return a.exec();
}
