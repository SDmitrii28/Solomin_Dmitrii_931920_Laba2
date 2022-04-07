#include "win9.h"
#include "win8.h"
#include "win.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win9 w9;
    Win8 w8;
    Win w;
    w.move(100,150);//сдвигаем окно интерфейса на позицию 100,150
    w.show();
    w8.move(400,150);//сдвигаем окно интерфейса на позицию 400,150
    w8.show();
    w9.move(700,150);//сдвигаем окно интерфейса на позицию 700,150
    w9.show();
    return a.exec();
}
