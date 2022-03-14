#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(const vector<string>& v)
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

    vector<string> n(N);

    for (int i = 0; i < n.size(); i++)
    {
        cin >> n[i];
    }

    sort(begin(n), end(n), [](string a, string b) { 
        std::for_each(a.begin(), a.end(), [](char& c) {
            c = ::tolower(c);
        });

        std::for_each(b.begin(), b.end(), [](char& c) {
            c = ::tolower(c);
        });

        return a < b; 
        }
    );


    //// сортируем
    //sort(begin(v), end(v),
    //    // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
    //    [](const string& l, const string& r) {
    //        // сравниваем лексикографически...
    //        return lexicographical_compare(
    //            // ... все символы строки l ...
    //            begin(l), end(l),
    //            // ... со всеми символами строки r ...
    //            begin(r), end(r),
    //            // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
    //            [](char cl, char cr) { return tolower(cl) < tolower(cr); }
    //        );
    //    }
    //);

    Print(n);


    return 0;
}
