#pragma once
#include <QPointF>
#include <QDebug>

class Ray {
public:
    Ray(const QPointF& begin, const QPointF& end);
    Ray(const QPointF& begin, double angle);

    void setBegin(const QPointF& newBegin);
    void setAngle(double angle);
    void setEnd(const QPointF& end);
    //    QPointF& getBegin();
    const QPointF& getBegin() const;
    const QPointF& getEnd() const;
    double getAngle() const;
    QPointF getVector() const;
    double size() const;

    Ray rotate(double angle) const;

private:
    QPointF begin_;
    QPointF end_;
    double angle_;
};