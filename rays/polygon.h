#pragma once
#include "ray.h"

class Polygon {
public:
    Polygon(const std::vector<QPointF>& vertices);
    Polygon();

    const QPointF& getVertex(int ind) const;
    const std::vector<QPointF>& getVertices() const;
    bool isEmpty() const;
    int size() const;

    void addVertex(const QPointF& vertex);
    void updateLastVertex(const QPointF& newVertex);
    std::optional<QPointF> intersectRay(const Ray& ray) const;

private:
    std::vector<QPointF> vertices_;
};