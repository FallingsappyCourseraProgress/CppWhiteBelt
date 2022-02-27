#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int x = 5;
    x = 6;
    
    cout << x;

    string s = "hello";
    string t = s;

    t += ", world";
    
    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    vector<string> w = { "a", "b", "c" };
    vector<string> v;

    v = w;

    v[0] = "d";

    for (int i = 0; i < w.size(); i++)
    {
        cout << w[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}
