#ifndef WIDGET_H
#define WIDGET_H

#include "../lib/stringprocessor.h"
#include "../lib/networkconnector.h"
#include "../lib/mathformulajsonconverter.h"


#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Button_1_clicked();

    void on_Button_7_clicked();

    void on_Button_8_clicked();

    void on_Button_9_clicked();

    void on_Button_plus_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_pushButton_minus_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_multiply_clicked();

    void on_Button_0_clicked();

    void on_Button_equals_clicked();

    void on_Button_divide_clicked();

    void on_Button_reset_clicked();

    void on_Button_Connect_Server_clicked();

    void updateLineEdit(const QString &message);

private:

    void clearIfErrorDisplayed();

private:
    Ui::Widget *ui;
    QString lineEditText;
    StringProcessor strProces;
    NetworkConnector net;
    MathFormulaJsonConverter matJson;

};
#endif // WIDGET_H
