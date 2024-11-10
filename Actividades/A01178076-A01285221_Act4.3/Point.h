#ifndef POINT_H
#define POINT_H

#define EPSILON 0.0001
#include <cmath>

class Point
{
private:
    double x, y;

public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point(const Point &p)
    {
        this->x = p.getX();
        this->y = p.getY();
    }
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
};

#endif