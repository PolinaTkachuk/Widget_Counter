#include "widget.h"
#include "ui_widget.h"

Win::Win(QWidget* parent) : QWidget(parent)
{
    this->setWindowTitle("Счетчик"); //устанавливаем заголовок окна
    label1 = new QLabel("Cчет по 1", this); //создание метки  с указание действия-Cчет по 1
    label2 = new QLabel("Cчет по 5", this);//метка-Cчет по 5
    edit1 = new Counter("0", this); //создаем редакторы ввода для счетчика1
    edit2 = new Counter("0",this);//для счетчика2
    calcbutton = new QPushButton("+1",this);// кнопка инкремента++1
    exitbutton = new QPushButton("Выход", this); // создание кнопки выхода
    QHBoxLayout* layout1 = new QHBoxLayout();               // горизонтальный компоновщик
      // добавляем виджеты
    layout1->addWidget(label1);// добавление метки1 к компоновщику
    layout1->addWidget(label2);// добавление метки2 к компоновщику
    QHBoxLayout* layout2 = new QHBoxLayout();               // горизонтальный компоновщик
    // добавляем виджеты
    layout2->addWidget(edit1);
    layout2->addWidget(edit2);
    QHBoxLayout* layout3 = new QHBoxLayout();               // горизонтальный компоновщик
    // добавляем виджеты
    layout3->addWidget(calcbutton); //для инкремента
    layout3->addWidget(exitbutton); //для выхода
    QVBoxLayout* layout4 = new QVBoxLayout(this);     // вертикальный компоновщик
    // добавляем компоновщики
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);
// связь сигналов и слотов
    connect(calcbutton, SIGNAL(clicked(bool)), edit1, SLOT(add_one())); //связь сигнала после нажатия кнопки добавляет 1
    connect(edit1, SIGNAL(tick_signal()), edit2, SLOT(add_one()));// вызов слота add_one, если вызвался сигнал tick_signal()
    connect(exitbutton, SIGNAL(clicked(bool)), this, SLOT(close()));//связь сигнала после нажатия кнопки выход-закрыв окно
}
