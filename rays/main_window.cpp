#include "main_window.h"
#include <QBrush>
#include <QDebug>
#include <QEvent>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <iostream>

int MainWindow::countLights = 6;
QBrush MainWindow::basePolygonBrush = QBrush();
QPen MainWindow::basePolygonPen = QPen();

MainWindow::MainWindow()
    : QMainWindow(nullptr),
      showWidget_(new QWidget(this)),
      scene_(new GraphicsScene(this)),
      view_(new GraphicsView(scene_, countLights)),
      controller_(new Controller(countLights)),
      mode_(new QComboBox(this)),
      layout_(new QGridLayout()),
      currentAreas_(std::vector<GraphicsPolygonItem*>(countLights)),
      lightsSources_(std::vector<QGraphicsEllipseItem*>(countLights)) {
    setUpStyle();
    setUpLayout();
    setUpBasePolygons();

    
    //    setUpScene();

    connect(view_, &GraphicsView::mousePressLeft, this, [&](const QPointF& point) {
        qDebug() << qRadiansToDegrees(Ray(QPointF(view_->width(), 0), point).getAngle());
        if (controller_->isDraw()) {
            controller_->addEmptyPolygon();
        }
        controller_->addVertexToLastPolygon(point);
    });
    connect(view_, &GraphicsView::mousePressRight, this, [&]() {
        if (controller_->isDraw()) {
            return;
        }
        scene_->addPolygon(controller_->getLastPolygon());
    });
    connect(mode_, &QComboBox::currentTextChanged, this, [&]() {
        if (mode_->currentText() == "polygons") {
            view_->setMode(GraphicsView::Mode::polygons);
            return;
        }
        if (mode_->currentText() == "light") {
            view_->setMode(GraphicsView::Mode::light);
            return;
        }
    });

    connect(view_, &GraphicsView::mouseMove, this, [&](const QPointF& light) {
        controller_->setLightSource(light);
        createEllipseLights(2.5);
        createLightArea(0.7);
    });

    qDebug() << "Main was build";
}

MainWindow::~MainWindow() {
    delete controller_;
    delete scene_;
    delete mode_;
    delete layout_;
}

void MainWindow::setUpStyle() {
    basePolygonBrush.setStyle(Qt::NoBrush);
    basePolygonPen.setColor(Qt::blue);
}

void MainWindow::setUpLayout() {
    resize(700, 700);
    setWindowTitle("Retraysing");
    mode_->addItem("light");
    mode_->addItem("polygons");
    layout_->addWidget(mode_, 0, 0);
    layout_->addWidget(view_, 1, 0);
    showWidget_->setLayout(layout_);
    view_->setMouseTracking(true);
    setCentralWidget(showWidget_);
    showWidget_->setMouseTracking(true);
}

void MainWindow::setUpBasePolygons() {
    controller_->addPolygon(Polygon(std::vector<QPointF>(
        {QPointF(200, 200), QPointF(200, 400), QPointF(400, 400), QPointF(400, 200)}
    )));
    scene_->addPolygon(controller_->getLastPolygon(), basePolygonBrush, basePolygonPen);
    controller_->setDraw(true);
    controller_->addPolygon(Polygon(
        std::vector<QPointF>({QPointF(0, 0), QPointF(0, 650), QPointF(680, 650), QPointF(680, 0)})
    ));
    controller_->setDraw(true);
}

void MainWindow::setUpScene() {

}

void MainWindow::createLightArea(double opacity) {
    const auto& areas = controller_->createLightArea();
    const auto& lights = controller_->getLights();
    for (int i = 0; i < countLights; ++i) {
        currentAreas_[i]->setPolygon(areas[i]);
        QRadialGradient gradient(lights[i], 400);
        gradient.setColorAt(0, QColor(255, 0, 0, 10));
        gradient.setColorAt(1, QColor(255, 0, 0, 100));
        currentAreas_[i]->setBrush(gradient);
        currentAreas_[i]->setOpacity(opacity);
    }
}

void MainWindow::createEllipseLights(double radius) {
    const auto& lights = controller_->getLights();
    for (int i = 0; i < countLights; ++i) {
        lightsSources_[i]->setRect(lights[i].x(), lights[i].y(), radius, radius);
    }
}

// void MainWindow::mouseMoveEvent(QMouseEvent* event) {
//     qDebug() << mapFromGlobal(QCursor::pos());
// }
//
// bool MainWindow::eventFilter(QObject* obj, QEvent* event) {
//     if (obj == centralWidget() && event->type() == QEvent::MouseMove) {
//         qDebug() << "here";
//         mouseMoveEvent(static_cast<QMouseEvent*>(event));
//         return true;
//     }
//     return QMainWindow::eventFilter(obj, event);
// }

//
// void MainWindow::setupScene() {
//    view_->setScene(scene_);
//}

// bool MainWindow::eventFilter(QObject* watched, QEvent* event) {
//     qDebug() << 3;
//     if (event->type() == QEvent::MouseMove) {
//         qDebug() << 2;
//     }
//     return QObject::eventFilter(watched, event);
// }

// bool MainWindow::event(QEvent* event) {
//     if (event->type() == QEvent::MouseMove) {
//         qDebug() << 2;
//     }
// }
