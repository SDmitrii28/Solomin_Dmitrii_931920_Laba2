#ifndef WIN8_H
#define WIN8_H

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

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
        QString str = text();
        int r = str.toInt();

        if (r != 0 && r % 5 == 0)
        {
            emit tick_signal();
        }

        r++;

        str.setNum(r);
        setText(str);
    }
};

class Win8 : public QWidget
{
    Q_OBJECT

protected:
    QLabel *label1, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;

public:
    Win8(QWidget *parent = nullptr);
};

#endif // WIN8_H
