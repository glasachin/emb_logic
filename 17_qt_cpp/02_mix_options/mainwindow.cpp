#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QDebug>

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

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Entered Value is: " << ui->lineEdit->text();
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    std::cout << "Changed Value: " << arg1.toStdString() << std::endl;
}

