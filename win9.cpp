#include "win9.h"
Win9::Win9()
{
    setWindowTitle("Обработка событий");
    area = new Area( this );
    btn = new QPushButton("Завершить");
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, &QPushButton::clicked ,this, &Win9::close);
};
