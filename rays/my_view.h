#pragma once

#include "my_scene.h"
#include <QCursor>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>

class GraphicsView : public QGraphicsView {
    Q_OBJECT

public:
    enum class Mode { polygons, light, staticLight };

public:
    GraphicsView(QGraphicsScene* scene, int countLight);

    void setLightMode();
    void setPolygonsMode();
    void setStaticLightMode();
    void setMode(const Mode& mode);

    Mode getCurrentMode() const;
    std::vector<GraphicsPolygonItem*>& getLightAreasItems();
    std::vector<QGraphicsEllipseItem*>& getLightSourceItems();

    void addLightArea(const QPointF& lightSource, const Polygon& polygon = Polygon());


protected:
    void resizeEvent(QResizeEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;


public:
signals:
    void mousePressLeft(const QPointF& vertex);
    void mousePressRight();
    void mouseMove(const QPointF& cursor);


private:
    Mode mode_;
    std::vector<GraphicsPolygonItem*> currentLightsAreasItems_;
    std::vector<QGraphicsEllipseItem*> lightsSourcesItems_;

    void setUpLights();
    void repaintLightAreas();
};