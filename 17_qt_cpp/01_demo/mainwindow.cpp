#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnManual, SIGNAL(clicked()), SLOT(manual_linked_btn())); //for manual button slot
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

void MainWindow::manual_linked_btn()
{
    std::cout << "Hi Manual button is pressed" << std::endl;
    ui->txtResult->setText("Manual");
}
