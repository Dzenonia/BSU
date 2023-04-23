#include "light_area.h"

LightAreaItem::LightAreaItem(const Polygon& polygon, const QPointF& center, double radius)
    : GraphicsPolygonItem(polygon), QGraphicsEllipseItem(center.x(), center.y(), radius, radius) {
    GraphicsPolygonItem::
}
