#pragma once

#include "polygon.h"
#include <QComboBox>
#include <QCursor>
#include <QGraphicsScene>
#include <QGridLayout>
#include <QLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPainter>
#include <QPushButton>

class Painter : public QWidget {
    Q_OBJECT

public:
    Painter();

    void drawPolygon(const Polygon& polygon, QPainter* painter);
};