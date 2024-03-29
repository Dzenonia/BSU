#include "ray.h"
#include <math.h>
#include <stdexcept>

Ray::Ray(const QPointF& begin, const QPointF& end) : begin_(begin), angle_(0), end_(end) {
    double dx = end.x() - begin.x();
    double dy = end.y() - begin.y();
    angle_ = atan2(dy, dx);
}

Ray::Ray(const QPointF& begin, double angle) : begin_(begin), angle_(angle) {
    end_.setX(begin_.x() + cos(angle_));
    end_.setY(begin_.y() + sin(angle_));
}


const QPointF& Ray::getBegin() const {
    return begin_;
}

void Ray::setBegin(const QPointF& newBegin) {
    begin_ = newBegin;
    double dx = end_.x() - begin_.x();
    double dy = end_.y() - begin_.y();
    angle_ = atan2(dy, dx);
}

void Ray::setAngle(double angle) {
    angle_ = angle;
}

double Ray::getAngle() const {
    return angle_;
}

Ray Ray::rotate(double angle) const {
    angle += angle_;
    double size = qSqrt(Ray::size());
    double dx = size * cos(angle);
    double dy = size * sin(angle);

    QPointF end(begin_.x() + dx * 1000, begin_.y() + dy * 1000);
    qDebug() << begin_ << " " << end;
    //    return Ray(begin_, angle);
    return Ray(begin_, end);
}

QPointF Ray::getVector() const {
    return QPointF(cos(angle_), sin(angle_));
}

const QPointF& Ray::getEnd() const {
    return end_;
}

double Ray::size() const {
    return (begin_.x() - end_.x()) * (begin_.x() - end_.x())
        + (begin_.y() - end_.y()) * (begin_.y() - end_.y());
}

void Ray::setEnd(const QPointF& end) {
    end_ = end;
    double dx = end.x() - begin_.x();
    double dy = end.y() - begin_.y();
    angle_ = atan2(dy, dx);
}
