#include "paint_widget.h"

void Painter::drawPolygon(const Polygon& polygon, QPainter* painter) {
    painter->save();


    painter->setBrush(Qt::black);

    const auto& vertices = polygon.getVertices();

    for (int i = 1; i < vertices.size(); ++i) {
        painter->drawLine(vertices[i], vertices[i - 1]);
    }


    painter->restore();
}

Painter::Painter() { }
