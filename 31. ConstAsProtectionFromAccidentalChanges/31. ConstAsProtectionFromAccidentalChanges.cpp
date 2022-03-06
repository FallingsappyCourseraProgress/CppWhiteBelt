#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    const int x = 5;

    // not allowed
    //x = 6;
    //x += 4;

    cout << x;

    const string s = "hello";
    cout << s.size() << endl;

    //not allowed
    //s += ", world";
    string t = s + "!";
    cout << s;

    const vector<string> w = { "hello" };
    
    //not allowed unlike javascript
    //w[0][0] = 'H';
    cout << w[0];

    return 0;
}
