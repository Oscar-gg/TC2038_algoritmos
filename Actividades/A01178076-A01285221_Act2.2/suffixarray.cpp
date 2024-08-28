// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Martes 27 de Agosto
// Programa para ordenar los suffix arrays

#include "libs.h"

using namespace std;

vector<int> suffixArrayNaive(string S)
{
    int n = S.length() + 1;
    vector<string> sa;
    vector<int> A(n);
    S = S + "$";
    for (int i = 0; i < n; i++)
        sa.push_back(S.substr(n - i - 1, i + 1));
    sort(sa.begin(), sa.end());
    for (int i = 0; i < n; i++)
        A[i] = n - sa[i].size() + 1;
    return A;
}

int main()
{
    string s;
    cout << "Ingrese el string para el suffix array: ";
    getline(cin, s);

    vector<int> res = suffixArrayNaive(s);

    cout << "Resultado: " << endl;

    for (auto x : res)
        cout << x << "\n";

    return 0;
}