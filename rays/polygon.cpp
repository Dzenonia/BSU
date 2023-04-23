#include "polygon.h"
#include <compare>
#include <iostream>
#include <QLineF>

Polygon::Polygon(const std::vector<QPointF>& vertices) : vertices_(vertices) { }

void Polygon::addVertex(const QPointF& vertex) {
    vertices_.push_back(vertex);
}

void Polygon::updateLastVertex(const QPointF& newVertex) {
    if (vertices_.empty()) {
        throw std::out_of_range("Polygon is empty");
    }
    vertices_.back() = newVertex;
}

const QPointF& Polygon::getVertex(int ind) const {
    if (vertices_.size() < ind) {
        throw std::out_of_range("There is no that point");
    }
    return vertices_[ind];
}

bool isPointOnLine(const QPointF& point, const QLineF& line) {
    const qreal distanceFromP1 = QLineF(line.p1(), point).length();
    const qreal distanceFromP2 = QLineF(line.p2(), point).length();
    const qreal lineLength = line.length();

    return qFuzzyCompare(distanceFromP1 + distanceFromP2, lineLength);
}

std::optional<QPointF> Polygon::intersectRay(const Ray& ray) const {
    double a1 = -sin(ray.getAngle());
    double b1 = cos(ray.getAngle());
    const double eps = 1e-8;

    auto intersectLine = [&](const QPointF& begin, const QPointF& end) {
        double a2 = -(end.y() - begin.y());
        double b2 = end.x() - begin.x();
        double c2 = (a2 * begin.x() + b2 * begin.y());
        double c1 = (a1 * ray.getBegin().x() + b1 * ray.getBegin().y());
        double det = (a1 * b2 - a2 * b1);
        if (fabs(det) <= eps) {
            return std::optional<QPointF>();
        }

        double x = (c1 * b2 - c2 * b1) / det;
        double y = (a1 * c2 - a2 * c1) / det;
        const QPointF point = QPointF(x, y);
        qDebug() << x << " " << y;

        Q_ASSERT(fabs(a1 * x + b1 * y - c1) <= eps);
        Q_ASSERT(fabs(a2 * x + b2 * x - c2) <= eps);


        if (!isPointOnLine(QPointF(x, y), QLineF(begin, end))) {
            return std::optional<QPointF>();
        }

        if (fabs(cos(ray.getAngle()) - cos(Ray(ray.getBegin(), point).getAngle())) <= eps
            && fabs(sin(ray.getAngle()) - sin(Ray(ray.getBegin(), point).getAngle())) <= eps) {
            return std::optional<QPointF>(QPointF(x, y));
        }
        return std::optional<QPointF>();
    };

    std::optional<QPointF> ans = std::optional<QPointF>();
    for (int i = 0; i < vertices_.size(); ++i) {
        auto point = intersectLine(vertices_[i], vertices_[(i + 1) % vertices_.size()]);
        if (point == std::optional<QPointF>()) {
            continue;
        }
        if (ans == std::optional<QPointF>()) {
            ans = point;
            continue;
        }
        double rxNow = point->x() - ray.getBegin().x();
        double ryNow = point->y() - ray.getBegin().y();

        double rx = ans->x() - ray.getBegin().x();
        double ry = ans->y() - ray.getBegin().y();
        if (rxNow * rxNow + ryNow * ryNow - eps <= rx * rx + ry * ry) {
            ans = point;
        }
    }
    return ans;
}

const std::vector<QPointF>& Polygon::getVertices() const {
    return vertices_;
}

Polygon::Polygon() : vertices_() { }

bool Polygon::isEmpty() const {
    return size() == 0;
}

int Polygon::size() const {
    return vertices_.size();
}
