#ifndef UNIT_CONVERTER_H
#define UNIT_CONVERTER_H

#include <QDialog>

namespace Ui {
class Unit_Converter;
}

class Unit_Converter : public QDialog
{
    Q_OBJECT

public:
    explicit Unit_Converter(QWidget *parent = nullptr);
    ~Unit_Converter();

private:
    Ui::Unit_Converter *ui;
    Unit_Converter *unit_converter;
};

#endif // UNIT_CONVERTER_H
