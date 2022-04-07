#include "win.h"

Win::Win(QWidget *parent)
    : QWidget(parent)
{
    //Рисунок 2.7 – Схема компоновки интерфейса приложения
    setWindowTitle("Возведение в квадрат");

    frame = new QFrame(this);// выделяем память под рамку
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputLabel = new QLabel("Введите число:", this);//сообщение где надо ввести число
    inputEdit = new QLineEdit("", this);//место где вводим число
    outputLabel = new QLabel("Результат:", this);//сообщение результата
    outputEdit = new QLineEdit("", this);//окно с результатом
    nextButton = new QPushButton("Следующее", this);//кнопка перехода к следующему вычислению
    exitButton = new QPushButton("Выход", this);//кнопка выхода
    //выделяем память под элементы интерфейса
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();

    connect(exitButton, &QPushButton::clicked, this, &Win::close);//сигнал закрытия интерфейса
    connect(nextButton, &QPushButton::clicked, this, &Win::begin);// сигнал нажатия на кнопку (следующее)
    connect(inputEdit, &QLineEdit::returnPressed, this, &Win::calc);//returnPressed()– сигнал нажатия клавиши Enter
}

void Win::begin()
{
    inputEdit->clear();//очистка полей с предыдущим вычислением
    nextButton->setEnabled(false);//делаем кнопку неактивной
    nextButton->setDefault(false);//видимость
    inputEdit->setEnabled(true);//делаем поле ввода не активным
    outputLabel->setVisible(false);//видимость
    outputEdit->setVisible(false);//видимость
    outputEdit->setEnabled(false);//делаем поле вывода не активным
    inputEdit->setFocus();//Передает фокус ввода с клавиатуры этому виджету
}

void Win::calc()
{
    bool Ok = true;
    float r, a;

    QString str = inputEdit->text();
    a = str.toDouble(&Ok);

    if (Ok)
    {
        r = a * a;

        str.setNum(r);

        outputEdit->setText(str);//выводим результат
        inputEdit->setEnabled(false);//делаем поле ввода неактивным
        outputLabel->setVisible(true);//видимость
        outputEdit->setVisible(true);//видимость
        nextButton->setDefault(true);
        nextButton->setEnabled(true);//делаем кнопку(следующее) активной
        nextButton->setFocus();
    }
    else if (!str.isEmpty())
    {
        //сообщение об ошибке
        QMessageBox msgBox(QMessageBox::Information, "Возведение в квадрат.", "Введено неверное значение.", QMessageBox::Ok);
        msgBox.exec();
    }
}
