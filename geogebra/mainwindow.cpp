//
// Created by evgeniy on 10.4.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    currentGraph_ = new QImage();
    currentGraph_->setText("1", "1");
}

MainWindow::~MainWindow() {

}

void MainWindow::generateGraph() { }
