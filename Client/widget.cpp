#include "widget.h"
#include "./ui_widget.h"

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

void Widget::on_Button_1_clicked()
{
    ui->lineEdit_number->setText(ui->lineEdit_number->text() + "1");
}


void Widget::on_Button_7_clicked()
{
    ui->lineEdit_number->setText(ui->lineEdit_number->text() + "7");
}


void Widget::on_Button_8_clicked()
{
  ui->lineEdit_number->setText(ui->lineEdit_number->text() + "8");
}


void Widget::on_Button_9_clicked()
{
    ui->lineEdit_number->setText(ui->lineEdit_number->text() + "9");
}


void Widget::on_Button_plus_clicked()
{
   ui->lineEdit_number->setText(ui->lineEdit_number->text() + "+");
}


void Widget::on_Button_4_clicked()
{
   ui->lineEdit_number->setText(ui->lineEdit_number->text() + "4");
}


void Widget::on_Button_5_clicked()
{
   ui->lineEdit_number->setText(ui->lineEdit_number->text() + "5");
}


void Widget::on_Button_6_clicked()
{
   ui->lineEdit_number->setText(ui->lineEdit_number->text() + "6");
}


void Widget::on_pushButton_minus_clicked()
{
    ui->lineEdit_number->setText(ui->lineEdit_number->text() + "-");
}


void Widget::on_Button_2_clicked()
{
    ui->lineEdit_number->setText(ui->lineEdit_number->text() + "2");
}


void Widget::on_Button_3_clicked()
{
    ui->lineEdit_number->setText(ui->lineEdit_number->text() + "3");
}


void Widget::on_Button_multiply_clicked()
{
    ui->lineEdit_number->setText(ui->lineEdit_number->text() + "*");
}


void Widget::on_Button_0_clicked()
{
    ui->lineEdit_number->setText(ui->lineEdit_number->text() + "0");
}


void Widget::on_Button_equals_clicked()
{    
    lineEditText = strProces.removeLastOperator(ui->lineEdit_number->text());
    ui->label_text_status->setText(lineEditText);
}


void Widget::on_Button_divide_clicked()
{
    ui->lineEdit_number->setText(ui->lineEdit_number->text() + "/");
}


void Widget::on_Button_reset_clicked()
{
    ui->lineEdit_number->clear();
}

