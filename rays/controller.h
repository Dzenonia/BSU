#pragma once
#include "polygon.h"

class Controller {
public:
    Controller(int count = 1);

    void addVertexToLastPolygon(const QPointF& newVertex);
    void updateLastPolygon(const QPointF& newVertex);
    void setLightSource(const QPointF& light);
    void addPolygon(const Polygon& polygon);
    void setDraw(bool isDraw);
    void addEmptyPolygon();

    const std::vector<Polygon>& getPolygons() const;
    const QPointF& getLightSource() const;
    const Polygon& getLastPolygon();

    bool isDraw() const;

    std::vector<std::optional<Ray>> castRays(const QPointF& lightSource) const;
    void intersectRays(std::vector<std::optional<Ray>>& rays) const;
    void removeAdjacentRays(std::vector<std::optional<Ray>>& rays, double dist = 1) const;
    std::vector<Polygon> createLightArea() const;
    const std::vector<QPointF>& getLights() const;

private:
    int countLights_;
    std::vector<Polygon> polygons_;
    QPointF lightSource_;
    std::vector<QPointF> lights_;
    bool isDraw_;
};
