// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Noviembre 24
// Implementación backtracking: El problema The Knight’s tour.

#include "libs.h"

using namespace std;

// O(1)
bool validPose(int x, int y, vector<vector<int>> &board)
{
    return x >= 0 && x < board.size() && y >= 0 && y < board.size() && board[x][y] == -1;
}

// O(8^(n^2))
// La complejidad es esa ya que, en el peor de los casos, el caballo puede, para cada posición, explorar 8 alternativas.
void exploreMap(int x, int y, vector<pair<int, int>> &moves, vector<vector<int>> &board, int &visited, int n)
{
    if (visited == n * n)
        return;

    board[x][y] = visited;
    visited++;
    for (auto move : moves)
    {
        int newX = x + move.first;
        int newY = y + move.second;

        if (validPose(newX, newY, board) && board[newX][newY] == -1)
        {
            exploreMap(newX, newY, moves, board, visited, n);
        }
    }
    if (visited < n * n)
    {
        board[x][y] = -1;
        visited--;
    }
}

int main()
{

    int n;
    cin >> n;

    // Espacio: O(n^2)
    vector<vector<int>> board(n, vector<int>(n, -1));

    int x = 0, y = 0;

    // 8 posibles movimientos para cada celda
    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    int visited = 0;

    // O(8^(N^2))
    exploreMap(x, y, moves, board, visited, n);

    if (visited == n * n)
    {
        // O(n^2)
        for (auto row : board)
        {
            for (auto cell : row)
            {
                cout << cell << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "No se encontró una solución.\n";
    }

    return 0;
}
