#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

//Оба счетчика будем строить на базе одного класса Counter, наследуемого от QLineEdit
class Counter : public QLineEdit // счетчик класс
{
Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
public:
    Counter(const QString& contents, QWidget* parent = nullptr) // конструктор
        : QLineEdit(contents, parent)
        {}
signals:
    void tick_signal();//сигнал
public slots:
    void add_one() //слот добавление единицы
    {
        QString str = text(); // считываем строку
        int r = str.toInt();  // получаем число из строки
        ++r;// добавл единицу к данному числу
        if (r != 0 && r % 5 == 0) emit tick_signal(); // если!= 0 и кратное пяти, вызываем сигнал
        str.setNum(r); // записываем в редактор
        setText(str);     //преобразовываем строку
    }
};


class Win : public QWidget // окно
{
Q_OBJECT// макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
    QLabel* label1, * label2; //создаем метки
    Counter* edit1, * edit2;  // создаем контейнеры
    QPushButton* calcbutton;  // кнопка для счета
    QPushButton* exitbutton;  // выход-кнопка
public:
    Win(QWidget* parent = nullptr); //конструктор, у которого параметр – родитель,
    //помощью этого параметра строятся иерархии объектов-виджетов
};

#endif // WIDGET_H
