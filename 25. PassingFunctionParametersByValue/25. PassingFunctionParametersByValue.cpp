#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintWords(vector<string> words)
{
    for (auto w : words)
    {
        cout << w << " ";
    }
}

void ChangeInt(int x)
{
    x = 42;
}

int main()
{
    PrintWords({ "air", "fire", "water" });

    int a = 5;
    ChangeInt(a);

    cout << a;

    return 0;
}
