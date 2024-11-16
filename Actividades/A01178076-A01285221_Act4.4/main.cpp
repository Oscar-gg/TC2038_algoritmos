// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Noviembre 15
// Implementación Randomized Binary Search

#include "libs.h"

using namespace std;

// Complejidad: O(logn)
// Peor caso: O(n) [siempre se elige l + 1 o r - 1. Sin embargo, la probabilidad de que esto ocurra es muy baja]
int randomizedBinarySearch(vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right)
    {
        int mid = left + (rand() % (right - left + 1));

        if (numbers[mid] == target)
        {
            return mid;
        }
        else if (numbers[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

vector<int> getNumbers(string &input)
{
    vector<int> nums;
    stringstream ss(input);
    string temp;

    while (std::getline(ss, temp, ','))
    {
        nums.push_back(std::stoi(temp));
    }

    return nums;
}

int main()
{
    srand(time(0));
    int targetNumber;
    cin >> targetNumber;
    cin.ignore();

    string s;
    getline(cin, s);

    // O(n)
    vector<int> numbers = getNumbers(s);

    // Se asume que el arreglo está ordenado
    // En caso de que no esté ordenado, no funcionará el algoritmo
    // Complejidad: O(logn). Peor caso: O(n)
    int index = randomizedBinarySearch(numbers, targetNumber);

    if (index >= 0)
    {
        cout << "El elemento esta presente en el indice: " << index << endl;
    }
    else
    {
        cout << "El elemento no esta presente en el arreglo" << endl;
    }

    return 0;
}
