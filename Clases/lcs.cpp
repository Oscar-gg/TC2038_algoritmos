// Oscar Arreola Alvarado A01178076
// Implementacion de LCS (Longest common substring)


#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

string longestCommonSubstring(string text1, string text2)
{
    // Arreglo dp del tamaño de ambas palabras
    vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1));

    int longest = 0;
    int endIndex = -1;

    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                // Reutilizar los resultados obtenidos hasta el momento
                dp[i][j] = 1 + dp[i - 1][j - 1];

                // Actualizar valores si el substring es más grande que los encontrados
                // hasta el momento
                if (dp[i][j] > longest){
                    longest = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    // Para depurar
    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //         cout << y << " ";
    //     cout << "\n";
    // }

    // cout << "longest: " << longest << "\n";
    // cout << "endindex: " << endIndex << "\n";

    return text1.substr(endIndex - longest + 1, longest);
}

int main()
{
    string s1, s2;
    cout << "Ingresa la primera string:";
    cin >> s1;
    cout << "Ingresa la segunda string:";
    cin >> s2;

    cout << "\n\nSubstring de mayor longitud: \"" << longestCommonSubstring(s1, s2) << "\"\n";

    return 0;
}