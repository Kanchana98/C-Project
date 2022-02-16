#include "currencydialog.h"
#include "ui_currencydialog.h"

CurrencyDialog::CurrencyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CurrencyDialog)
{
    ui->setupUi(this);
}

CurrencyDialog::~CurrencyDialog()
{
    delete ui;
}
