#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Gt2(int x)
{
    return x > 2;
}

bool Lt2(int x)
{
    return x < 2;
}

int main()
{
    vector<int> v{ 1, 3, 2, 5, 4, 2 };

    int numberOfOccurances = 0;
    for (auto i : v)
    {
        if (i == 2)
        {
            numberOfOccurances++;
        }
    }

    cout << count(begin(v), end(v), 2) << endl;
    cout << count_if(begin(v), end(v), Gt2) << endl;
    cout << count_if(begin(v), end(v), Lt2) << endl;

    cout << count_if(begin(v), end(v), [](int x) { return x > 2; }) << endl;

    int thr = 0;
    cin >> thr;

    cout << count_if(begin(v), end(v), [thr](int x) { return thr > 2; }) << endl;

    return 0;
}