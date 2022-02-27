#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool smallest(std::string const& lhs, std::string const& rhs) {
    return lhs < rhs;
}

int main()
{
    string a, b, c;

    cin >> a >> b >> c;

    vector<string> st = { a, b, c };

    cout << *min_element(begin(st), end(st), smallest);

    return 0;
}
