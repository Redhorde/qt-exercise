#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "add_value.h"
#include "qdialogbuttonbox.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_userList->setRowCount(database.Size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    // TODO finish json load functionality
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Json"), "./", tr("Json file (*.json)"));
    ui->label->setText(filename);
}

void MainWindow::on_actionSave_triggered()
{
    // TODO finish saving database to json functionality
    QString save_filename = QFileDialog::getSaveFileName(this, tr("Save Json"), "./", tr("*.json"));
    ui->label->setText(save_filename);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

// This is the slot opening a new window with an option for adding values
void MainWindow::on_actionAdd_value_triggered()
{
    Add_value add_value_dialog;
    add_value_dialog.setWindowTitle("Add value");
    if (add_value_dialog.exec() == QDialog::Accepted)
    {
        std::vector<QString> dialogData = add_value_dialog.GetValues();
//        for (auto& i: dialogData)
//        {
//            std::cout<<"Dialog data: "<< i.toStdString() <<std::endl;
//        }
        try
        {
            User_model newUser(dialogData[0].toStdString(), dialogData[1].toStdString(), dialogData[2].toStdString());
            database.push_back(newUser);

            ui->label->setText("User list");
            UpdateTable(database);
        }
        catch (const std::invalid_argument& e)
        {
            QMessageBox::StandardButton option;
            option = QMessageBox::question(this, "Role not found", "Role not found in roles list. Do you want to add it??",
                                          QMessageBox::Yes|QMessageBox::No);

            if (option == QMessageBox::Yes)
            {
                User_model newUser(dialogData[0].toStdString(), dialogData[1].toStdString(), dialogData[2].toStdString());
                database.addRole(newUser.getUserRole());
                database.push_back(newUser);

                ui->label->setText("User list");
                UpdateTable(database);
            }
            std::cerr<<e.what();
        }

    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "QT project for testing purposes \n\n Marcel Koczorowski 2023");
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this);
}

// Removes value from database based on selected tableWidget row
void MainWindow::on_pushButton_remove_clicked()
{
    int selectedRow = ui->tableWidget_userList->currentRow();
    if (selectedRow==-1)
    {
        QMessageBox::warning(this, "Warning", "Nothing selected");
    }
    else
    {
        database.user_list.erase(database.user_list.begin()+selectedRow);
        UpdateTable(database);
    }
}

// Call this function every time database has been modified
void MainWindow::UpdateTable(Data_model database)
{
    ui->tableWidget_userList->setRowCount(database.Size());

    int row = 0;
    for (auto& user: database.user_list)
    {
        ui->tableWidget_userList->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(user.getUserName())));
        ui->tableWidget_userList->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(user.getUserSurname())));
        ui->tableWidget_userList->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(user.getUserRole())));
        row ++;
    }
}

