#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string_render.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Main : public QMainWindow {
Q_OBJECT

public:
    Main(QWidget *parent = nullptr);

    ~Main();

private slots:

    void getAns();

    void exit();

    void checkInputBase();

    void checkInputValue();

    void checkOutputBase();

    void addString();

    void printQString();

    void renderQString();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
