#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_Number;
bool User_Type_SecNumber = false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->P_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->P_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->P_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->P_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->P_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->P_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->P_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->P_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->P_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->P_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->P_plusORminus,SIGNAL(released()),this,SLOT(Unary_Pressed()));
    connect(ui->P_percent,SIGNAL(released()),this,SLOT(Unary_Pressed()));

    connect(ui->P_plus,SIGNAL(released()),this,SLOT(Binary_Pressed()));
    connect(ui->P_minus,SIGNAL(released()),this,SLOT(Binary_Pressed()));
    connect(ui->P_multiply,SIGNAL(released()),this,SLOT(Binary_Pressed()));
    connect(ui->P_division,SIGNAL(released()),this,SLOT(Binary_Pressed()));

    ui->P_plus->setCheckable(true);
    ui->P_minus->setCheckable(true);
    ui->P_multiply->setCheckable(true);
    ui->P_division->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
   QPushButton * button = (QPushButton*)sender();

   double LNumber;
   QString NewLabel;

   if ((ui->P_plus->isChecked() || ui->P_division->isChecked() ||
           ui->P_multiply->isChecked() || ui->P_division->isChecked()) && (!User_Type_SecNumber))
   {
       LNumber = button->text().toDouble();
       User_Type_SecNumber = true;
       NewLabel = QString::number(LNumber,'g',15);
   }
   else
   {
       if (ui->label->text().contains('.') && button->text()=="0")
       {
           NewLabel = ui->label->text() + button->text();
       }
       else
       {
            LNumber = (ui->label->text()+button->text()).toDouble();
            NewLabel = QString::number(LNumber,'g',15);
       }

   }

   ui->label->setText(NewLabel);
}


void MainWindow::on_P_decimal_released()
{
    ui->label->setText(ui->label->text()+".");
}

void MainWindow::Unary_Pressed(){
    QPushButton * button = (QPushButton*) sender();
    double LNumber;
    QString NewLabel;

    if(button->text() == "+/-")
    {
        LNumber = ui->label->text().toDouble();
        LNumber = LNumber * -1;
        NewLabel =QString::number(LNumber,'g',15);
        ui->label->setText(NewLabel);
    }
    if(button->text() == "%")
    {
        LNumber = ui->label->text().toDouble();
        LNumber = LNumber * 0.01;
        NewLabel =QString::number(LNumber,'g',15);
        ui->label->setText(NewLabel);
    }
}


void MainWindow::on_P_clear_released()
{
    ui->P_plus->setChecked(false);
    ui->P_minus->setChecked(false);
    ui->P_multiply->setChecked(false);
    ui->P_division->setChecked(false);

    User_Type_SecNumber = false;

    ui->label->setText("0");
}


void MainWindow::on_P_equal_released()
{
    double label_Num, second_Number;
    QString NewLabel;

    second_Number = ui->label->text().toDouble();


    if(ui->P_plus->isChecked())
    {
        label_Num = first_Number + second_Number;
        NewLabel = QString::number(label_Num,'g',15);
        ui->label->setText(NewLabel);
        ui->P_plus->setChecked(false);

    }
    else if(ui->P_minus->isChecked())
    {
        label_Num = first_Number - second_Number;
        NewLabel = QString::number(label_Num,'g',15);
        ui->label->setText(NewLabel);
        ui->P_minus->setChecked(false);
    }
    else if(ui->P_multiply->isChecked())
    {
        label_Num = first_Number * second_Number;
        NewLabel = QString::number(label_Num,'g',15);
        ui->label->setText(NewLabel);
        ui->P_multiply->setChecked(false);
    }
    else if(ui->P_division->isChecked())
    {
        label_Num = first_Number / second_Number;
        NewLabel = QString::number(label_Num,'g',15);
        ui->label->setText(NewLabel);
        ui->P_division->setChecked(false);
    }
    User_Type_SecNumber = false;
}

void MainWindow::Binary_Pressed()
{
    QPushButton * button = (QPushButton*) sender();

    first_Number = ui->label->text().toDouble();
    button->setChecked(true);

}




void MainWindow::on_P_11_clicked()
{
//    SecDialog secDialog;
//    secDialog.setModal(true);
//    secDialog.exec();
    secDialog = new SecDialog(this);
    secDialog->show();
}


void MainWindow::on_P_10_clicked()
{
    currencyDialog = new CurrencyDialog(this);
    currencyDialog->show();
}

