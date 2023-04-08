#include "widget.h"
#include "mainwindow.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    MainWindow * w=new MainWindow(this);
    this->close();
    w->show();
}

