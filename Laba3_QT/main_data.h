#pragma once
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

class Data : public QObject {

    Q_OBJECT
public:
    Data();

public slots:
    void saveData();
    void checkData();
    void setName(const QString&);
    void setSurname(const QString& surname);
    void setPatronymic(const QString& patronymic);

private:
    QString name_;
    QString surname_;
    QString patronymic_;
};