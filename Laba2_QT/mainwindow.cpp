#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <algorithm>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->getAns, &QPushButton::clicked, this, &MainWindow::getAns);
    connect(ui->exit, &QPushButton::clicked, this, &MainWindow::exit);
    connect(ui->valueInput, &QLineEdit::editingFinished, this, &MainWindow::checkInputValue);
    connect(ui->baseInput, &QLineEdit::editingFinished, this, &MainWindow::checkInpuBase);
    connect(ui->baseOutput, &QLineEdit::editingFinished, this, &MainWindow::checkOutputBase);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit() {
    QCoreApplication::quit();
}

void MainWindow::checkInputValue() {
    if (ui->valueInput->text().size() == 0) {
        ui->labelValue->setStyleSheet("QLabel {color: black}");
        ui->labelValue->setText("Введите значение");
        return;
    }
    if (ui->baseInput->text().size() == 0) {
        ui->labelValue->setStyleSheet("QLabel {color: green}");
        ui->labelValue->setText("Ошибок нет");
        return;
    }
}

void MainWindow::checkInpuBase() {

}

void MainWindow::checkOutputBase() {

}


void MainWindow::getAns() {
    bool check = 1;
    int base = ui->baseInput->text().toInt();
    int value = ui->valueInput->text().toInt(0, base);
    int ouBase = ui->baseOutput->text().toInt();
    ui->result->setText(QString::number(value, ouBase));
}


