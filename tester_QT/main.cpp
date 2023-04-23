#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QCursor>
#include <QMouseEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создаем сцену
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 400, 400);

    // Создаем объект-точку
    QGraphicsEllipseItem point(-5, -5, 10, 10);
    point.setPos(QCursor::pos());
    scene.addItem(&point);

    // Создаем виджет просмотра сцены
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.show();

    // Обновляем позицию точки при перемещении курсора
    QObject::connect(&view, &QGraphicsView::cursorPositionChanged, [&point](){
        point.setPos(QCursor::pos());
        point.update();
    });

    return a.exec();
}
