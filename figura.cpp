#include <math.h>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter)
{
    dx=halflen*cos(Alpha);//координата поворота по x
    dy=halflen*sin(Alpha);//координата поворота по y
    draw(Painter);
}
void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);//рисуем линию после поворота
}
void MyRect::draw(QPainter *Painter)
{
    //рисуем линии сторок квадрата после поворота
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
