/* Instrucciones */

// Utilizando la técnica de programación de "divide y vencerás", escribe en equipos de máximo dos personas,
// en C++ un programa que implemente el algoritmo de MergeSort.

// El programa recibe un numero entero N, seguido de N valores reales (double, uno en cada línea) por la entrada estándar.
// La salida del programa es una lista de los N valores ordenados de Mayor a menor
// Tu programa debe ser llamado main.cpp

// Sube un archivo ZIP que se llame <tumatricula_Act1.1>.ZIP
//      El archivo ZIP contiene una carpeta (folder) llamada <tumatricula_Act1.1>, y dentro se encuentra el archivo "main.cpp"
//      Es posible tener más archivos dentro de la carpeta

#include <iostream>
#include <vector>

using namespace std;

// Complejidad temporal: O(r - l + 1)
// Complejidad espacial: O(r - l + 1)
void merge(vector<double> &arreglo, int l, int m, int r, bool descendente=false){
    vector<double> temporal;
    int p1 = l, p2 = m+1;

    while (p1 <= m || p2 <= r){
        if (p1 <= m && p2 <= r){
            if ((arreglo[p1] < arreglo[p2]) ^ descendente){
                temporal.push_back(arreglo[p1++]);
            } else {
                temporal.push_back(arreglo[p2++]);
            }
        } else if (p1 <= m){
            temporal.push_back(arreglo[p1++]);
        } else {
            temporal.push_back(arreglo[p2++]);
        }
    }

    for(int i = l; i <= r; i++){
        arreglo[i] = temporal[i-l];
    }

}

// O(Nlog(N)), donde N es el tamaño del arreglo inicial
// Cada operacion de merge toma O(N) tiempo
// Y esta operacion se realiza log(N) veces
void mergeSort(vector<double> &arreglo, int l, int r, bool descendente=false){
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSort(arreglo, l, m, descendente);
        mergeSort(arreglo, m+1, r, descendente);

        merge(arreglo, l, m, r, descendente);
    }
}

int main(){
    cout << "Ingrese N: ";
    int n;
    cin >> n;

    // Validar que el valor de N sea válido.
    if (n < 0){
        cout << "N no puede ser menor a 0.\n";
        return 0;
    }

    vector<double> arreglo(n);
    
    // Llenar el arreglo de valores
    for(int i = 0; i < n; i++){
        cout << "Ingrese el valor " << i+1 << ": ";
        cin >> arreglo[i];
        cout << "\n";
    }

    // Aplicar el algoritmo
    mergeSort(arreglo, 0, arreglo.size()-1, true);

    // Mostrar el resultado
    cout << "\n\nResultado: ";
    for(double elemento : arreglo){
        cout << elemento << " ";
    }

    return 0;
}