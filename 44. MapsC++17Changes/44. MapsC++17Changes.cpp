#include <map>
#include <iostream>
using namespace std;

int main()
{
    map<string, int> m = {{"one", 1}, {"two", 2}};

    int s = m["three"];

    // C++17 
    //for (const auto& [key, value] : m)
    //{
    //    key, value;
    //}

    return 0;
}