//
// Created by evgeniy on 10.4.23.
//

#ifndef BSU_MAINWINDOW_H
#define BSU_MAINWINDOW_H

#include <QCoreApplication>
#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void generateGraph();


private:
    QImage* currentGraph_;
};


#endif // BSU_MAINWINDOW_H
