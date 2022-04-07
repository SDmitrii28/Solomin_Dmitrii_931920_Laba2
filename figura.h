#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>
class Figura
{
    protected:
        int x,y,halflen,dx,dy,r;//координаты и размер фигуры
        virtual void draw(QPainter *Painter)=0;
    public:
        Figura(int X,int Y,int Halflen):
        x(X),y(Y),halflen(Halflen){}//конструктор с размеров и положением объекта
        void move(float Alpha,QPainter *Painter);
};
//КЛАСС линии
class MyLine:public Figura
{
    protected:
        void draw(QPainter *Painter);
    public:
        MyLine(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор с размеров и позицией
};
//КЛАСС квадрата
class MyRect:public Figura
{
    protected:
        void draw(QPainter *Painter);
    public:
        MyRect(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор с размеров и позицией
};
#endif // FIGURA_H
