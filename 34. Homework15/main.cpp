#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void Reverse(vector<int>& v)
{
    reverse(v.begin(), v.end());
}

void ReverseManual(vector<int>& v) {
    int n = v.size();  // для удобства сохраним размер вектора в переменную n
    for (int i = 0; i < n / 2; ++i) {
        // элемент с индексом i симметричен элементу с индексом n - 1 - i
        // поменяем их местами с помощью временной переменной tmp
        int tmp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = tmp;
    }
}


int main()
{
    vector<int> numbers = { 1, 5, 3, 4, 2 };
    Reverse(numbers);
    // numbers должен оказаться равен {2, 4, 3, 5, 1}

    return 0;
}
