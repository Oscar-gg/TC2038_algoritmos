// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Octubre 13
// Programa para implementar Dijkstra y Floyd

#include "libs.h"

using namespace std;

typedef pair<int, int> pii;

// Implementacion de camino más corto, 
int dijkstraHelper(int source, int target, unordered_map<int, vector<pair<int, int>>> &graph)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    unordered_set<int> visited;

    pq.push({0, source});

    while (!pq.empty())
    {
        auto front = pq.top();
        visited.insert(front.second);
        pq.pop();

        if (front.second == target)
            return front.first;

        for (auto neighbour : graph[front.second])
        {
            if (!visited.count(neighbour.first))
            {
                pq.push({front.first + neighbour.second, neighbour.first});
            }
        }
    }

    return -1;
}

void dijkstra(vector<vector<int>> &matrix)
{
    unordered_map<int, vector<pair<int, int>>> graph;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (i != j && matrix[i][j] != -1)
                graph[i].push_back({j, matrix[i][j]});
        }
    }

    cout << "Dijkstra :\n";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (i != j)
                cout << "node " << i + 1 << " to node " << j + 1 << " : " << dijkstraHelper(i, j, graph) << "\n";
        }
    }

    cout << "\n\n";
}

void floyd(vector<vector<int>> matrix)
{

    int v = matrix.size();

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    cout << "Floyd :\n";

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int next;
            cin >> next;
            matrix[i][j] = next;
        }

    dijkstra(matrix);

    floyd(matrix);

    return 0;
}