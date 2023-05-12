#include "add_value.h"
#include "ui_add_value.h"

Add_value::Add_value(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_value)
{
    ui->setupUi(this);
}

Add_value::~Add_value()
{
    delete ui;
}
