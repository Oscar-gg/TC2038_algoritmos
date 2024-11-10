// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Noviembre 10
// Implementación búsqueda geométrica

#include "Point.h"
#include "libs.h"

using namespace std;

// Función auxiliar para calcular la distancia entre dos puntos
// O(1)
double dist(Point &a, Point &b)
{
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

// Función para encontrar la distancia más corta entre dos puntos

double closest_pair_util(int l, int r, vector<Point> &points)
{
    // Si hay menos de 4 puntos, calcular la distancia entre todos los puntos con fuerza bruta
    if (r - l <= 3)
    {
        double min_dist = INT_MAX;
        for (int i = l; i < r; i++)
            for (int j = i + 1; j < r; j++)
                min_dist = min(min_dist, dist(points[i], points[j]));
        return min_dist;
    }

    int mid = (l + r) / 2;
    double mid_x = points[mid].getX();
    double d = min(closest_pair_util(l, mid, points), closest_pair_util(mid, r, points));

    // Considerar los puntos que están a una distancia menor a d del punto medio
    // O(n) - n es el número de puntos
    vector<Point> strip;
    for (int i = l; i < r; i++)
        if (abs(points[i].getX() - mid_x) < d)
            strip.push_back(points[i]);

    // Ordenar los puntos en strip respecto a su coordenada y
    // O(nlogn) - n es el número de puntos.
    // Sin embargo, como strip tiene a lo mucho 6 puntos, la complejidad se podría considerar O(1)
    sort(strip.begin(), strip.end(), [](Point &a, Point &b)
         { return a.getY() < b.getY(); });

    double min_strip = d;
    // Calcular la distancia entre los puntos en strip
    // O(n^2) - n es el número de puntos en strip.
    // Sin embargo, como strip tiene a lo mucho 6 puntos, la complejidad se podría considerar O(1)
    for (int i = 0; i < strip.size(); i++)
        for (int j = i + 1; j < strip.size() && strip[j].getY() - strip[i].getY() < min_strip; j++)
            min_strip = min(min_strip, dist(strip[i], strip[j]));

    return min(d, min_strip);
}

double closest_pair(vector<Point> &points)
{
    // Ordenar los puntos respecto a su coordenada x
    // O(nlogn) - n es el número de puntos
    sort(points.begin(), points.end(), [](Point &a, Point &b)
         { return a.getX() < b.getX(); });

    // Llamar a la función auxiliar
    return closest_pair_util(0, points.size(), points);
}

int main()
{
    int n;
    cin >> n;

    vector<Point> points;

    // Leer y guardar todos los puntos.
    // O(n) - n es el número de puntos
    for (int i = 0; i < n; i++)
    {
        char c;
        int x, y;
        cin >> x >> c >> y;
        Point next(x, y);
        points.push_back(next);
    }
    // O(nlogn) - n es el número de puntos
    cout << "La distancia mas corta es: " << closest_pair(points) << endl;

    return 0;
}
