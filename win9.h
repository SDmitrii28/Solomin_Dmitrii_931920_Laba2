#ifndef WIN9_H
#define WIN9_H

#include <QWidget>
#include <QPushButton>
#include <QtGui>
#include <QVBoxLayout>
#include "area.h"
class Win9 : public QWidget
{
    protected:
        Area * area; // область отображения рисунка
        QPushButton * btn;
    public:
        Win9();
};

#endif // WIN9_H
