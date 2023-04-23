#pragma once
#include "controller.h"
#include "graphics_polygon.h"
#include "my_view.h"
#include <QBasicTimer>
#include <QComboBox>
#include <QCursor>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QTimerEvent>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    static int countLights;
    static QBrush basePolygonBrush;
    static QPen basePolygonPen;
    MainWindow();
    ~MainWindow();

private:
    QWidget* showWidget_;
    Controller* controller_;
    GraphicsScene* scene_;
    GraphicsView* view_;
    QComboBox* mode_;
    QGridLayout* layout_;
    std::vector<GraphicsPolygonItem*> currentAreas_;
    std::vector<QGraphicsEllipseItem*> lightsSources_;


    void setUpStyle();
    void setUpLayout();
    void setUpBasePolygons();
    void setUpScene();
    void createLightArea(double opacity);
    void createEllipseLights(double radius);
};
