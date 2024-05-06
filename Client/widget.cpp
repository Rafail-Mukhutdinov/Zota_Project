#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&net, &NetworkConnector::messageReceived, this, &Widget::updateLineEdit);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Button_1_clicked()
{
    QString currentText = ui->lineEdit_number->text() + "1";
    ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
}


void Widget::on_Button_7_clicked()
{
    QString currentText = ui->lineEdit_number->text() + "7";
    ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
}


void Widget::on_Button_8_clicked()
{
    QString currentText = ui->lineEdit_number->text() + "8";
    ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
}


void Widget::on_Button_9_clicked()
{
    QString currentText = ui->lineEdit_number->text() + "9";
    ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
}


void Widget::on_Button_plus_clicked()
{
    QString currentText = ui->lineEdit_number->text();

    if(currentText.isEmpty())
    {
        ui->label_text_status->setText("Incorrect expression");
    }
    else
    {
        QString newText = strProces.replaceLastOperator(currentText, '+');
        ui->lineEdit_number->setText(newText);
    }
}


void Widget::on_Button_4_clicked()
{
    QString currentText = ui->lineEdit_number->text() + "4";
    ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
}


void Widget::on_Button_5_clicked()
{
    QString currentText = ui->lineEdit_number->text() + "5";
    ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
}


void Widget::on_Button_6_clicked()
{
    QString currentText = ui->lineEdit_number->text() + "6";
    ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
}


void Widget::on_pushButton_minus_clicked()
{
    QString currentText = ui->lineEdit_number->text();

    if(currentText.isEmpty())
    {
        ui->label_text_status->setText("Incorrect expression");
    }
    else
    {
        QString newText = strProces.replaceLastOperator(currentText, '-');
        ui->lineEdit_number->setText(newText);
    }
}


void Widget::on_Button_2_clicked()
{
    QString currentText = ui->lineEdit_number->text() + "2";
    ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
}


void Widget::on_Button_3_clicked()
{
    QString currentText = ui->lineEdit_number->text() + "3";
    ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
}


void Widget::on_Button_multiply_clicked()
{
    QString currentText = ui->lineEdit_number->text();

    if(currentText.isEmpty())
    {
        ui->label_text_status->setText("Incorrect expression");
    }
    else
    {
        QString newText = strProces.replaceLastOperator(currentText, '*');
        ui->lineEdit_number->setText(newText);
    }

}


void Widget::on_Button_0_clicked()
{
    QString currentText = ui->lineEdit_number->text();

    if(currentText.isEmpty())
    {
        ui->label_text_status->setText("Incorrect expression");
    }
    else
    {
        QString currentText = ui->lineEdit_number->text() + "0";
        ui->lineEdit_number->setText(strProces.removeLeadingZeroAfterOperator(currentText));
    }
}



void Widget::on_Button_equals_clicked()
{
    QString currentText = ui->lineEdit_number->text();

    if(currentText.isEmpty())
    {
        ui->label_text_status->setText("Incorrect expression");
    }else
    {
        if (net.socketState() == QAbstractSocket::ConnectedState)
        {

            lineEditText = strProces.removeLastOperator(ui->lineEdit_number->text());
            net.sendMessage(lineEditText);
            ui->label_text_status->setText("Message sent: " + lineEditText);
        } else
        {
            ui->label_text_status->setText("No connection to server.");
        }
    }
}


void Widget::on_Button_divide_clicked()
{
    QString currentText = ui->lineEdit_number->text();

    if(currentText.isEmpty())
    {
        ui->label_text_status->setText("Incorrect expression");
    }
    else
    {
        QString newText = strProces.replaceLastOperator(currentText, '/');
        ui->lineEdit_number->setText(newText);
    }
}


void Widget::on_Button_reset_clicked()
{
    ui->lineEdit_number->clear();
}


void Widget::on_Button_Connect_Server_clicked()
{
    if (net.socketState() == QAbstractSocket::UnconnectedState)
    {
        net.connectToServer(QHostAddress::LocalHost, 1234);

        if (net.getSocket()->waitForConnected(5000))
        {
            ui->Button_Connect_Server->setText("Disconnect from the Server");
        }
        else
        {
            ui->label_text_status->setText("Server is not available");
        }
    }
    else if (net.socketState() == QAbstractSocket::ConnectedState)
    {
        net.disconnectFromServer();
        ui->Button_Connect_Server->setText("Connect to the Server");
    }
}

void Widget::updateLineEdit(const QString &message)
{
    ui->lineEdit_number->setText(message); // Обновляем lineEdit полученным сообщением
}

