// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Jueves 15 de Agosto
// Programa para probar la implementación del algoritmo MergeSort


#include <iostream>
#include <vector>
using namespace std;

// Complejidad temporal: O(r - l + 1)
// Complejidad espacial: O(r - l + 1)
// Función merge para combinar los sub-arreglos
void merge(vector<double> &arreglo, int l, int m, int r, bool descendente=false) {
    vector<double> temporal;
    int p1 = l, p2 = m+1;

    while (p1 <= m || p2 <= r) {
        if (p1 <= m && p2 <= r) {
            if ((arreglo[p1] < arreglo[p2]) ^ descendente) {
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

    for(int i = l; i <= r; i++) {
        arreglo[i] = temporal[i-l];
    }

}

// O(Nlog(N)), donde N es el tamaño del arreglo inicial
// Cada operacion de merge toma O(N) tiempo
// Y esta operacion se realiza log(N) veces
// Función merge sort para dividir el problema en sub-problemas
void mergeSort(vector<double> &arreglo, int l, int r, bool descendente=false) {
    if(l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arreglo, l, m, descendente);
        mergeSort(arreglo, m+1, r, descendente);

        merge(arreglo, l, m, r, descendente);
    }
}

// Función principal para recibir las entradas e imprimir el resultado
int main() {
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
    for(int i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i+1 << ": ";
        cin >> arreglo[i];
        cout << "\n";
    }

    // Aplicar el algoritmo
    mergeSort(arreglo, 0, arreglo.size()-1, true);

    // Mostrar el resultado
    cout << "\n\nResultado: ";
    for(double elemento : arreglo) {
        cout << elemento << " ";
    }

    return 0;
}