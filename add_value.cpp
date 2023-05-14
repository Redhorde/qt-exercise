#include "add_value.h"
#include "ui_add_value.h"

Add_value::Add_value(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_value)
{
    ui->setupUi(this);
}

// Passes values from the dialog
std::vector<QString> Add_value::GetValues()
{
    std::vector<QString> dialogData;
    dialogData.push_back(ui->lineEdit_name->text());
    dialogData.push_back(ui->lineEdit_surname->text());
    dialogData.push_back(ui->lineEdit_role->text());
    return dialogData;
}

Add_value::~Add_value()
{
    delete ui;
}
