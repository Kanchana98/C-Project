#ifndef CURRENCYDIALOG_H
#define CURRENCYDIALOG_H

#include <QDialog>

namespace Ui {
class CurrencyDialog;
}

class CurrencyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CurrencyDialog(QWidget *parent = nullptr);
    ~CurrencyDialog();

private:
    Ui::CurrencyDialog *ui;
};

#endif // CURRENCYDIALOG_H
