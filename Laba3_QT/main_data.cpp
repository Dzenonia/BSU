#include "main_data.h"
#include <QDebug>

Data::Data() { }

void Data::saveData() {
    QJsonObject employeeJson;
    employeeJson["name"] = name_;
    employeeJson["surname"] = surname_;
    employeeJson["patronymic"] = patronymic_;
    qDebug() << employeeJson;
    QJsonDocument jsonDoc(employeeJson);
    QFile file("data/test.json");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write(jsonDoc.toJson());
    file.close();
}

void Data::checkData() { }

void Data::setName(const QString& name) {
    name_ = name;
    qDebug() << name_;
}

void Data::setSurname(const QString& surname) {
    surname_ = surname;
}

void Data::setPatronymic(const QString& patronymic) {
    patronymic_ = patronymic;
}
