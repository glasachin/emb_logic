#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

int firstNo, secondNo, result;

void MainWindow::on_btnSum_clicked()
{
    firstNo = ui->txtNum1->text().toInt();
    secondNo = ui->txtNum2->text().toInt();
    result = firstNo + secondNo;

    ui->txtResult->setText(QString::number(result));

}


void MainWindow::on_btnSub_clicked()
{
    firstNo = ui->txtNum1->text().toInt();
    secondNo = ui->txtNum2->text().toInt();
    result = firstNo - secondNo;

    ui->txtResult->setText(QString::number(result));
}


void MainWindow::on_btnMul_clicked()
{
    firstNo = ui->txtNum1->text().toInt();
    secondNo = ui->txtNum2->text().toInt();
    result = firstNo * secondNo;

    ui->txtResult->setText(QString::number(result));
}


void MainWindow::on_btnDiv_clicked()
{
    firstNo = ui->txtNum1->text().toInt();
    secondNo = ui->txtNum2->text().toInt();
    result = firstNo / secondNo;

    ui->txtResult->setText(QString::number(result));
}

