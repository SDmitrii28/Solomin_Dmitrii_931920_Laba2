#include "area.h"
Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));//размер окна интерфейса
    myline=new MyLine(80,100,50);//позиция и размер линии
    myrect=new MyRect(220,100,50);//позиция и размер квадрата
    alpha=0;//угол поворота
}
//включение таймера;
void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(50); // создать таймер
}
//рисование пошагово перемещающихся фигур;
void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::red);//цвет
    myline->move(alpha,&painter);//поворот линии
    myrect->move(alpha*(-0.5),&painter);//поворот квадрата
}
//инициация перерисовки Холста;
void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2;//изменяем угол альфа
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной
// обработки
}
//выключение таймера.
void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // уничтожить таймер
}
Area::~Area()
{
    delete myline;
    delete myrect;
}
