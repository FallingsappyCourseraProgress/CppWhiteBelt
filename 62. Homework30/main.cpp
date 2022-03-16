#include <iostream>
#include <vector>
using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        if (strings.size() == 0)
        {
            strings.push_back(s);
            return;
        }

        for (int i = 0; i < strings.size(); i++)
        {
            if (strings[i] < s)
            {
                strings.insert(strings.begin() + i, s);
                return;
            }
        }
    }
    vector<string> GetSortedStrings() {
        return strings;
    }
private:
    vector<string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
