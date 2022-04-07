#ifndef WIN8_H
#define WIN8_H

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

//оба объекта счетчиков должны уметь увеличивать свое содержимое
//на единицу, т.е. включать соответствующий метод – слот. А первый счетчик должен генерировать сигнал при достижении пяти нажатий.
class Counter : public QLineEdit
{
    Q_OBJECT

public:
    Counter(const QString &contents, QWidget *parent = nullptr) : QLineEdit(contents, parent) {}

signals:
    void tick_signal(); // сигнал, вызываемый при счете, кратном пяти

public slots:
    void add_one()
    {
        QString str = text();//переводим строку в текст
        int r = str.toInt();//переводим текст в число

        if (r != 0 && r % 5 == 0)
        {
            emit tick_signal();
        }

        r++;//увеличиваем счетчик

        str.setNum(r);//переводим число в текст
        setText(str);//отображаем текст
    }
};

class Win8 : public QWidget
{
    Q_OBJECT

protected:
    //инициализируем элементы интерфейса
    QLabel *label1, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;

public:
    Win8(QWidget *parent = nullptr);
};

#endif // WIN8_H
