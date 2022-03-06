#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Sum(int x, int y)
{
    return x + y;
}

bool Contains(vector<string> words, string w)
{
    for (auto s : words)
    {
        if (s == w)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int x, y;
    
    cin >> x >> y;

    cout << x + y;
    cout << Sum(x, y);

    cout << Contains({ "air", "water", "fire" }, "fire");

    return 0;
}