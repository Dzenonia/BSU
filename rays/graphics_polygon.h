#pragma once

#include "polygon.h"
#include <QGraphicsPolygonItem>
#include <QObject>

class GraphicsPolygonItem : public QGraphicsPolygonItem {

public:
    GraphicsPolygonItem(const Polygon& polygon = Polygon(), QGraphicsItem* parent = nullptr);

    void setPolygon(const Polygon& polygon = Polygon());
};