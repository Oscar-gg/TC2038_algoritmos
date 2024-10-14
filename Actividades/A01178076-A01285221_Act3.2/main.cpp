// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Octubre 13
// Programa para implementar Dijkstra y Floyd

#include "libs.h"

using namespace std;

typedef pair<int, int> pii;

// Implementación de camino más corto de un nodo a todos los nodos.
// Complejidad temporal: O((V + E)log(V))
void dijkstraHelper(int source, unordered_map<int, vector<pair<int, int>>> &graph, unordered_map<int, int> &result)
{
    // Inicializar estructura para ordenar nodos a visitar por proximidad
    // Min priority queue
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Marcar el origen como nodo por visitar
    pq.push({0, source});
    
    // Continuar mientras haya nodos por visitar
    while (!pq.empty()) // O(V + E)
    {
        // Obtener nodo más cercano
        auto front = pq.top();
        pq.pop(); // O(log(V))

        // Si ya se exploró el nodo, continuar
        if (result.count(front.second))
            continue;

        // Guardar el resultado para el nodo actual, en caso de que sea visitado por primera vez
        result[front.second] = front.first;

        // Explorar todos los vecinos del nodo actual
        // O(vecinos)
        for (auto neighbour : graph[front.second])
        {
            // Considerar edge solo si no se ha visitado el otro nodo.
            if (!result.count(neighbour.first))
            {
                // O(log(V))
                // Peso de visitar nodo = peso actual + peso de usar el camino.
                pq.push({front.first + neighbour.second, neighbour.first});
            }
        }
    }
}

void dijkstra(vector<vector<int>> &matrix)
{
    // Cambiar formato de grafo
    unordered_map<int, vector<pair<int, int>>> graph;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            // Agregar edge si es entre nodos diferentes y si existe.
            if (i != j && matrix[i][j] != -1)
                graph[i].push_back({j, matrix[i][j]});
        }
    }

    cout << "Dijkstra :\n";
    for (int i = 0; i < matrix.size(); i++)
    {
        // Obtener resultados de un nodo a todos los demás
        unordered_map<int, int> results;
        dijkstraHelper(i, graph, results);
        
        // Imprimir todos los resultados
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (i != j){
                string result = results.count(j) ? to_string(results[j]) : "no path";
                cout << "node " << i + 1 << " to node " << j + 1 << " : " << result << "\n";
            }
                
        }
    }

    cout << "\n\n";
}

// O(V^3)
void floyd(vector<vector<int>> matrix)
{
    int v = matrix.size();

    // Cambiar formato para facilitar dp de floyd warshall
    // O(V^2)
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }

    // O(V^3)
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                // Para cada nodo intermedio K, considerar si la distancia de "i" a "k" + "k" a "j" 
                // Es menor a la distancia actual grabada del nodo i al j. 
                // En caso de que si, actualizar solución óptima
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Imprimir resultados
    cout << "Floyd :\n";
    
    // O(V^2)
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

    // O(V^2)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int next;
            cin >> next;
            matrix[i][j] = next;
        }

    // La complejidad de hacer dijkstra de un nodo a todos es: O(V + E)log(V))
    // Como la implementación actual hace un dijkstra para cada vertice V, la complejidad
    // resulta en: O(V * (V + E)log(V))
    dijkstra(matrix);

    // O(V^3)
    floyd(matrix);

    return 0;
}