#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(const vector<int>& v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    int N;

    cin >> N;

    vector<int> n(N);

    for (int i = 0; i < N; i++)
    {
        cin >> n[i];
    }

    sort(n.begin(), n.end(), [](int a, int b) { return abs(a) < abs(b); });;

    Print(n);

    return 0;
}