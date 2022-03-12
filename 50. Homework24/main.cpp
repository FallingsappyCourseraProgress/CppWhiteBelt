#include <set>
#include <iostream>
using namespace std;

int main()
{
    int N;

    cin >> N;

    set<string> unique;
    
    for (int i = 0; i < N; i++)
    {
        string c;

        cin >> c;

        unique.insert(c);
    }

    cout << unique.size();

    return 0;
}
