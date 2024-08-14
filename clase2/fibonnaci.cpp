#include <iostream>
#include <vector>


using namespace std;

int fibonnaci(int n, vector<int>& dp){
    if (dp[n] != -1)
        return dp[n];
    
    return dp[n] = fibonnaci(n-1, dp) + fibonnaci(n-2, dp);
}

int main(){
    int n;
    cout << "Ingresar el numero de fibonnaci a calcular: ";
    cin >> n;
    cout << "\n";

    vector<int> dp(n+1, -1);
    dp[0]=0;
    dp[1]= 1;

    cout << "Resultado: ";
    cout << fibonnaci(n, dp) << "\n";

    for(auto x: dp){
        cout << x << " ";
    }
    
}