#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <algorithm>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QString>
#include <QtCore>
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->getAns, &QPushButton::clicked, this, &MainWindow::getAns);
    connect(ui->exit, &QPushButton::clicked, this, &MainWindow::exit);
    connect(ui->valueInput, &QLineEdit::editingFinished, this, &MainWindow::checkInputValue);
    connect(ui->baseInput, &QLineEdit::editingFinished, this, &MainWindow::checkInputBase);
    connect(ui->baseOutput, &QLineEdit::editingFinished, this, &MainWindow::checkOutputBase);
    connect(ui->addStrToList, &QPushButton::clicked, this, &MainWindow::addString);
    connect(ui->QString, &QRadioButton::clicked, this, &MainWindow::renderQString);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::exit() {
    QCoreApplication::quit();
}

void MainWindow::checkInputValue() {
    const auto &label = ui->valueInput->text();
    if (label.size() == 0) {
        ui->labelValue->setStyleSheet("QLabel {color: black}");
        ui->labelValue->setText("Введите значение");
        return;
    }
    bool check = 1;
    int value = label.toInt(&check, 10);
    if (!check) {
        ui->labelValue->setStyleSheet("QLabel {color: red}");
        ui->labelValue->setText("Введите целое значение!");
        return;
    }
    ui->labelValue->setStyleSheet("QLabel {color: green}");
    ui->labelValue->setText("Ошибок нет!");
}

void MainWindow::checkInputBase() {
    const auto &label = ui->baseInput->text();
    if (label.size() == 0) {
        ui->labelInputBase->setStyleSheet("QLabel {color: black}");
        ui->labelInputBase->setText("Начальная СС");
        return;
    }
    bool check = 1;
    int value = label.toInt(&check, 10);
    if (!check || value < 2 || value > 16) {
        ui->labelInputBase->setStyleSheet("QLabel {color: red}");
        ui->labelInputBase->setText("Ошибка ввода!");
        return;
    }
    ui->labelInputBase->setStyleSheet("QLabel {color: green}");
    ui->labelInputBase->setText("Ошибок нет!");
}

void MainWindow::checkOutputBase() {
    const auto &label = ui->baseOutput->text();
    if (label.size() == 0) {
        ui->labelOutputBase->setStyleSheet("QLabel {color: black}");
        ui->labelOutputBase->setText("Итоговая СС");
        return;
    }
    bool check = 1;
    int value = label.toInt(&check, 10);
    if (!check || value < 2 || value > 16) {
        ui->labelOutputBase->setStyleSheet("QLabel {color: red}");
        ui->labelOutputBase->setText("Ошибка ввода!");
        return;
    }
    ui->labelOutputBase->setStyleSheet("QLabel {color: green}");
    ui->labelOutputBase->setText("Ошибок нет!");
}


void MainWindow::getAns() {
    if (ui->labelInputBase->text() != "Ошибок нет!" || ui->labelOutputBase->text() != "Ошибок нет!" ||
        ui->labelValue->text() != "Ошибок нет!") {
        ui->result->setStyleSheet("QLabel {color: red}");
        ui->result->setText("Ошибка получения ответа! Есть ошибки!");
        return;
    }
    bool check = 1;
    int base = ui->baseInput->text().toInt();
    int value = ui->valueInput->text().toInt(&check, base);
    if (!check) {
        ui->result->setStyleSheet("QLabel {color: red}");
        ui->result->setText("Ошибка получения ответа! Есть ошибки!");
        return;
    }
    int ouBase = ui->baseOutput->text().toInt();
    ui->result->setStyleSheet("QLabel {color: green}");
    ui->result->setText(QString::number(value, ouBase));
}

void MainWindow::addString() {
    QString current = ui->textAddStr->text();
    if (current.isEmpty()) {
        return;
    }
    ui->textEdit->append(current);
}

void MainWindow::printQString() {
    ui->textBrowser->setText(ui->textEdit->toPlainText());
}

void MainWindow::renderQString() {
    QString text = ui->textEdit->toPlainText();

    QStringList list = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (list.size() <= 2) {
        return;
    }
    QString longer = list[0];
    QString shorter = list[0];
    for (const auto &word: list) {
        if (word.size() > longer.size()) {
            longer = word;
        }
        if (word.size() <= shorter.size()) {
            shorter = word;
        }
    }
    std::cout << shorter.toStdString() << " " << longer.toStdString() << std::endl;
    std::cout << text.toStdString() << std::endl;
    int posLonger = text.indexOf(longer);
    int posShorter = text.lastIndexOf(shorter);
    std::cout << posLonger << " " << posShorter << std::endl;
    if (posLonger > posShorter) {
        text.replace(posLonger, longer.length(), shorter);
        text.replace(posShorter, shorter.length(), longer);
    } else {
        text.replace(posShorter, shorter.length(), longer);
        text.replace(posLonger, longer.length(), shorter);
    }



    ui->textBrowser->setText(text);
}



