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

    static int orientation(Point a, Point b, Point c)
    {
        double v = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
        if (v < 0)
            return -1;
        if (v > 0)
            return 1;
        return 0;
    }

    static bool cw(Point a, Point b, Point c, bool include_collinear)
    {
        int o = orientation(a, b, c);
        return o < 0 || (include_collinear && o == 0);
    }

    static bool collinear(Point a, Point b, Point c) { return orientation(a, b, c) == 0; }
};

#endif