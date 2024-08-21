#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<int>> &mat) {

    if (mat.size() == 0 || mat[0].size() == 0){
        cout << "[]\n(La matriz esta vacia)" << endl;
        return;
    }

    int m = mat.size();
    int n = mat[0].size();

    int limiteAltoCol = n-1;
    int limiteBajoCol = 0;

    int limiteAltoRow = m-1;
    int limiteBajoRow = 0;

    int elementos = m*n;
    int explored = 0;

    while (explored < elementos){
        for(int i = limiteBajoCol ; i <= limiteAltoCol && explored < elementos; i++){
            cout << mat[limiteBajoRow][i] << " ";
            explored++;
        }
        for(int i = limiteBajoRow+1 ; i <= limiteAltoRow && explored < elementos; i++){
            cout << mat[i][limiteAltoCol] << " ";
            explored++;
        }
        for(int i = limiteAltoCol-1; i >= limiteBajoCol && explored < elementos; i--){
            cout << mat[limiteAltoRow][i] << " ";
            explored++;
        }
        for(int i = limiteAltoRow-1; i >= limiteBajoRow+1 && explored < elementos; i--){
            cout << mat[i][limiteBajoCol] << " ";
            explored++;
        }
        limiteBajoCol++;
        limiteAltoCol--;
        limiteBajoRow++;
        limiteAltoRow--;
    }

    cout << endl;

}
 
int main() {

    int m, n;
    cout << "Ingrese M (cantidad de filas): ";
    cin >> m;
    cout << "Ingrese N (cantidad de columnas): ";
    cin >> n;
    
    vector<vector<int>> matriz(m, vector<int>(n));


    cout << matriz.size() << endl;
    
    for(int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz[i].size(); j++){
            int x;
            cout << "Ingrese el valor de la posicion [" << i << "][" << j << "]: ";
            cin >> x;
            matriz[i][j] = x;
        }
    }

    solve(matriz);

    return 0;
}

// Ejemplos de matrices
// vector<vector<int>> matriz1 = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };

// [1,2,3,6,9,8,7,4,5]

// vector<vector<int>> matriz2 = {
//     {1, 2, 3, 4},
//     {5, 6, 7, 8},
//     {9, 10, 11, 12}
// };

// [1,2,3,4,8,12,11,10,9,5,6,7]