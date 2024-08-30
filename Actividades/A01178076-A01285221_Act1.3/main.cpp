
// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Viernes 30 de Agosto
// Programa para probar la implementación de los algoritmos backtracking y branch and bound

#include "libs.h"
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define pb push_back

vector<ii> moves = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vi> btSolution;
vector<vi> bbSolution;
int solSize = INT_MAX;

/*
    Función para checar si el siguiente movimiento es válido
    Recibe el laberinto y posición a checar
    Retorna verdadero si es posible o falso de lo contrario
    Complejidad: O(1)
*/
inline bool isValid(vector<vi> & maze, int i, int j) {
    return (i >= 0 && j >= 0 && i < maze.size() && j < maze[0].size() && maze[i][j] == 1);
}

/* 
    Solución BackTracking, recorre todas las posibilidades y si encuentra una mejor solución
    actualiza la respuesta
    Recibe el laberinto, camino actual, tamaño del camino actual, posición actual
    Complejidad O(4^(n*m))
*/
void backTracking(vector<vi> & maze, vector<vi> curr, int currSize, int i_, int j_) {
    curr[i_][j_] = 1;
    maze[i_][j_] = 0;
    currSize++;

    if (i_ == maze.size()-1 && j_ == maze[0].size() - 1) {
        if (currSize < solSize) {
            btSolution = curr;
            solSize = currSize;
        }
    }

    for (ii move : moves) {
        int nextI = i_ + move.first;
        int nextJ = j_ + move.second;

        if (isValid(maze, nextI, nextJ)) {
            backTracking(maze, curr, currSize, nextI, nextJ);
        }
    }

    maze[i_][j_] = 1;
}

/*
    Función Branch and Bound, recorre todos los caminos, pero se podan aquellos cuyo tamaño 
    es más largo que la respuesta actual.
    Recibe el laberinto, camino actual, tamaño del camino actual, posición actual
    Complejidad O(4^(n*m))
*/
void branchAndBound(vector<vi> & maze, vector<vi> curr, int currSize, int i_, int j_) {
    if (currSize >= solSize) return;

    curr[i_][j_] = 1;
    maze[i_][j_] = 0;
    currSize++;

    if (i_ == maze.size()-1 && j_ == maze[0].size() - 1) {
        if (currSize < solSize) {
            bbSolution = curr;
            solSize = currSize;
        }
    }
    
    for (ii move : moves) {
        int nextI = i_ + move.first;
        int nextJ = j_ + move.second;

        if (isValid(maze, nextI, nextJ)) {
            branchAndBound(maze, curr, currSize, nextI, nextJ);
        }
    }
    maze[i_][j_] = 1;
}

/*
    Imprime el camino que soluciona el laberinto en caso de que se haya encontrado
    Recibe la matriz de solución a imprimir
*/
void print(vector<vi> & solution) {
    if (solution.size() == 0) {
        cout << "No solution" << endl;
    }

    for (int i = 0; i < solution.size(); i++) {
        for (int j = 0; j < solution[0].size(); j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

/*
    Función main para recibir inputs y llamar a los algoritmos
    Se busca encontrar el camino más corto para llegar a la salida
    Se imprime una de las posibles respuestas
*/
int main() { 
    int m,n,x;
    cin >> m >> n;

    vector<vi> maze(m,vi(n,0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            maze[i][j] = x;
        }
    }

    // Resolver con backtracking
    cout << "Solución con backtracking: " << endl;
    backTracking(maze, vector<vi>(m,vi(n, 0)), 0, 0, 0);
    print(btSolution);
    solSize = INT_MAX;

    // Resolver con branch and bound
    cout << "\nSolución con branch and bound: " << endl;
    branchAndBound(maze, vector<vi>(m,vi(n,0)), 0, 0, 0);
    print(bbSolution);
    return 0;
}

