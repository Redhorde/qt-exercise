#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "add_value.h"
#include "data_model.h"


// TODO implement data_model in the application
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Json"), "./", tr("Json file (*.json)"));
    ui->label->setText(filename);
}

void MainWindow::on_actionSave_triggered()
{
    QString save_filename = QFileDialog::getSaveFileName(this, tr("Save Json"), "./", tr("*.json"));
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
    add_value_dialog.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "QT project for testing purposes \n\n Marcel Koczorowski 2023");
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_pushButton_remove_clicked()
{
    ui->label->setText("No data");
}

