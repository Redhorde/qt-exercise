#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "data_model.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Data_model database;
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionAdd_value_triggered();

    void on_pushButton_remove_clicked();

    void UpdateTable(Data_model database);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
