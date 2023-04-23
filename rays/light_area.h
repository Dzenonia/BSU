#pragma once

#include "graphics_polygon.h"
#include <QGraphicsEllipseItem>

class LightAreaItem : public GraphicsPolygonItem {

public:
    LightAreaItem(const Polygon& polygon, const QPointF& center, double radius);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr)
        override;


private:
    QGraphicsEllipseItem ellipseItem_;
};