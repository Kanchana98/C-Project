#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SecDialog.h"
#include "currencydialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SecDialog *secDialog;
    CurrencyDialog * currencyDialog;

private slots:
    void digit_pressed();

    void on_P_decimal_released();
    void Unary_Pressed();
    void on_P_clear_released();
    void on_P_equal_released();
    void Binary_Pressed();
    void on_P_11_clicked();
    void on_P_10_clicked();
};
#endif // MAINWINDOW_H
