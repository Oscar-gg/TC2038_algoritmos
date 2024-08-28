// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Martes 27 de Agosto
// Programa para calcular el hash de un string

#include "libs.h"
 
using namespace std;

// Funcion para hashear una string
long long hashString(string &s){
    long long int resultado = 0;
    int p = 31, m  = 1e9 + 9;
    long long n = s.size(), potencia = 1;;
    
    for(int i = 0; i < n; i++){
        resultado = (resultado + (s[i] - 'a' + 1) * (long long)potencia) % m;
        potencia = (potencia * p) % m;
    }
    
    return resultado;
}
 
int main() { 
    string s;
    cout << "Ingrese el string a hashear: ";
    getline(cin, s);
    
    cout << "Resultado: " << hashString(s) << endl;

    return 0;
}