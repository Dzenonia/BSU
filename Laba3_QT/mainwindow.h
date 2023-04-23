#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "main_data.h"
#include <QMainWindow>

class Main : public QMainWindow {
    Q_OBJECT

public:
    Main(QWidget* parent = nullptr);

    ~Main();

private slots:
    void exit();



//private: signals:
//    void saveData();



private:
    Ui::MainWindow* ui;
    Data * currentData_;
};

#endif // MAINWINDOW_H
