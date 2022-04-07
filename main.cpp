#include "win8.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win8 w;
    w.move(100,150);//сдвигаем окно интерфейса на позицию 100,150
    w.show();
    return a.exec();
}
