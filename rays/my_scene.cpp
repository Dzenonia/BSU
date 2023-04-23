#include "my_scene.h"


void GraphicsScene::addPolygon(const Polygon& polygon, const QBrush& brush, const QPen& pen) {
    //    QPen currentPen{};
    //    currentPen.setColor(Qt::blue);
    //    currentPen.setWidthF(2);
    //    const auto& vertices = polygon.getVertices();
    //    for (int i = 0; i < vertices.size(); ++i) {
    //        QGraphicsLineItem* currentLine = new QGraphicsLineItem(
    //            vertices[i].x(), vertices[i].y(), vertices[(i + 1) % vertices.size()].x(),
    //            vertices[(i + 1) % vertices.size()].y()
    //        );
    //        currentLine->setPen(currentPen);
    //
    //        addItem(currentLine);
    //    }
    GraphicsPolygonItem* newPolygonItem = new GraphicsPolygonItem(polygon);
    newPolygonItem->setBrush(brush);
    newPolygonItem->setPen(pen);
    addItem(newPolygonItem);
}

GraphicsScene::GraphicsScene(QObject* parent)
    : QGraphicsScene(parent), currentLightsSourcesItems_(), currentAreasItems_() { }

void GraphicsScene::addLightArea(const QPointF& lightSource, const Polygon& polygon) {
    GraphicsPolygonItem* newPolygonItem = new GraphicsPolygonItem(polygon);
    QGraphicsEllipseItem* newLightSource =
        new QGraphicsEllipseItem(lightSource.x(), lightSource.y(), 2.5, 2.5);
    addItem(newPolygonItem);
    addItem(newLightSource);
    currentAreasItems_.push_back(newPolygonItem);
    currentLightsSourcesItems_.push_back(newLightSource);
}

const std::vector<QGraphicsEllipseItem*>& GraphicsScene::getLightSourceItems() const {
    return currentLightsSourcesItems_;
}

const std::vector<GraphicsPolygonItem*>& GraphicsScene::getLightAreasItems() const {
    return currentAreasItems_;
}


