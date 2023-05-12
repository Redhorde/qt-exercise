#ifndef ADD_VALUE_H
#define ADD_VALUE_H

#include <QDialog>

namespace Ui {
class Add_value;
}

class Add_value : public QDialog
{
    Q_OBJECT

public:
    explicit Add_value(QWidget *parent = nullptr);
    ~Add_value();

private:
    Ui::Add_value *ui;
};

#endif // ADD_VALUE_H
