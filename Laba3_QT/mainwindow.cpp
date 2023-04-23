#include "ui_mainwindow.h"
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPixmap>
#include <QPushButton>
#include <QString>
#include <QtCore>
#include <algorithm>
#include <iostream>
#include <mainwindow.h>

Main::Main(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentData_(new Data()) {
    ui->setupUi(this);
    ui->photoWorker->setPixmap(QPixmap("/home/evgeniy/Изображения/man2.png"));
    connect(ui->save, &QPushButton::clicked, currentData_, &Data::saveData);
    connect(ui->exit, &QPushButton::clicked, this, &Main::exit);
//    connect(
//        ui->name, SIGNAL(QLineEdit::textChanged(const QString&)), currentData_,
//        SLOT(Data::setName(const QString&))
//    );
    connect(ui->nameLine, &QLineEdit::textEdited, currentData_, &Data::setName);
    connect(ui->surnameLine, &QLineEdit::textEdited, currentData_, &Data::setSurname);
    connect(ui->patronymicLine, &QLineEdit::textEdited, currentData_, &Data::setPatronymic);
}

Main::~Main() {
    delete ui;
}

void Main::exit() {
    QCoreApplication::quit();
}
