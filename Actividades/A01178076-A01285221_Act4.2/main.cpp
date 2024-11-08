// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Noviembre 7
// Programa para implementar Graham's Scan, para encontrar el polígono convexo
// más pequeño en un conjunto de puntos.

// Implementación basada en: https://cp-algorithms.com/geometry/convex-hull.html

// Complejidad de operaciones O(1)

#include "Point.h"
#include "libs.h"

using namespace std;

Point p0;

// O(1)
bool compare(const Point &a, const Point &b)
{
    int o = Point::orientation(p0, a, b);
    if (o == 0)
        return (p0.getX() - a.getX()) * (p0.getX() - a.getX()) + (p0.getY() - a.getY()) * (p0.getY() - a.getY()) < (p0.getX() - b.getX()) * (p0.getX() - b.getX()) + (p0.getY() - b.getY()) * (p0.getY() - b.getY());
    return o < 0;
}

// O(1)
bool compare_pivot(const Point &a, const Point &b)
{
    return a.getY() < b.getY() || (a.getY() == b.getY() && a.getX() < b.getX());
}

int main()
{
    vector<Point> points;

    // Leer y guardar todos los puntos.
    int x, y;
    // O(n) - n es el número de puntos
    while (cin >> x && cin >> y)
    {
        Point next(x, y);
        points.push_back(next);
    }

    // Bandera para saber si se incluyen los puntos colineares
    bool include_collinear = false;

    // obtener el punto de pivote (que esta hasta abajo a la derecha)
    // O(n) - n es el número de puntos
    p0 = *min_element(points.begin(), points.end(), compare_pivot);

    // Ordenar los puntos respecto al angulo con el punto de pivote
    // O(nlogn) - n es el número de puntos
    sort(points.begin(), points.end(), compare);

    // Formar el convex hull
    vector<Point> st;

    // O(n) - n es el número de puntos
    for (int i = 0; i < points.size(); i++)
    {
        // Mientras el siguiente punto haga un giro a la derecha, quitar el penultimo punto
        while (st.size() > 1 && !Point::cw(st[st.size() - 2], st.back(), points[i], include_collinear))
            st.pop_back();
        st.push_back(points[i]);
    }

    if (include_collinear == false && st.size() == 2 && (st[0].getX() == st[1].getX() && st[0].getY() == st[1].getY()))
        st.pop_back();

    points = st;

    // Imprimir el resultado.
    // Imprimir los puntos al reves para imprimir en orden contrario al sentido de las manecillas del reloj.
    // O(n) - n es el número de puntos
    for (int i = points.size(); i > 0; i--)
    {
        Point x = points[i % points.size()];
        cout << x.getX() << " " << x.getY() << endl;
    }

    return 0;
}
