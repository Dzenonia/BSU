#include "my_view.h"
#include <QMouseEvent>

GraphicsView::GraphicsView(QGraphicsScene* scene, int countLights)
    : QGraphicsView(scene),
      mode_(Mode::light),
      currentLightsAreas_(std::vector<GraphicsPolygonItem*>(countLights)),
      lightsSources_(std::vector<QGraphicsEllipseItem*>(countLights)) {
    setRenderHint(QPainter::Antialiasing, true);
    setRenderHint(QPainter::SmoothPixmapTransform, true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setInteractive(false);
    setDragMode(QGraphicsView::NoDrag);
    setLightMode();
    setUpLights();
}

void GraphicsView::setLightMode() {
    setMouseTracking(true);
    setBackgroundBrush(Qt::black);
    setSceneRect(0, 0, QWidget::width(), QWidget::height());
    QPixmap iconCursor(10, 10);
    iconCursor.fill(Qt::transparent);
    QPainter painter(&iconCursor);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(iconCursor.rect());

    QCursor cursor(iconCursor);

    //    setCursor(cursor);

    mode_ = Mode::light;
}

void GraphicsView::resizeEvent(QResizeEvent* event) {
    setSceneRect(0, 0, QWidget::width(), QWidget::height());
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event) {
    qDebug() << mapFromGlobal(cursor().pos());
    switch (mode_) {
        case Mode::polygons:
            break;
        case Mode::light:
            emit mouseMove(mapFromGlobal(cursor().pos()));
            break;
        case Mode::staticLight:
            break;
    }
}

void GraphicsView::mousePressEvent(QMouseEvent* event) {

    switch (mode_) {
        case Mode::light:
            break;
        case Mode::polygons:
            if (event->button() == Qt::LeftButton) {
                emit mousePressLeft(mapFromGlobal(cursor().pos()));
            } else {
                emit mousePressRight();
            }
            break;
        case Mode::staticLight:
            break;
    }
}

void GraphicsView::setMode(const GraphicsView::Mode& mode) {
    switch (mode) {
        case Mode::polygons:
            setPolygonsMode();
            break;
        case Mode::light:
            setLightMode();
            break;
        case Mode::staticLight:
            mode_ = mode;
            break;
    }
}

void GraphicsView::setPolygonsMode() {
    mode_ = Mode::polygons;
}

void GraphicsView::setUpLights() {
    double dd = 0.2;
    double now = 0.2;

    for (int i = 0; i < currentLightsAreas_.size(); ++i) {
        if (now + 1e-8 >= 1.0) {
            dd = -dd;
        }
        currentLightsAreas_[i] = new GraphicsPolygonItem();
        currentLightsAreas_[i]->setBrush(QBrush(Qt::red));
        currentLightsAreas_[i]->setPen(Qt::NoPen);
        currentLightsAreas_[i]->setOpacity(0.5);


        lightsSources_[i] = new QGraphicsEllipseItem();
        lightsSources_[i]->setBrush(Qt::white);
        lightsSources_[i]->setPen(Qt::NoPen);
        lightsSources_[i]->setZValue(1);


        //        lightsSources_[i]->setOpacity(1);

        //        QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
        //        shadowEffect->setBlurRadius(100); // радиус размытия тени
        //        shadowEffect->setColor(Qt::red); // цвет тени
        //        shadowEffect->setOffset(100, 100); // смещение тени
        //        currentLightsAreas_[i % 4]->setGraphicsEffect(shadowEffect);


        now += dd;

        scene()->addItem(currentLightsAreas_[i]);
        scene()->addItem(lightsSources_[i]);
    }
}

void GraphicsView::repaint() { }

void GraphicsView::repaintLightAreas() {
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

// void GraphicsView::setPolygonsMode() { }
