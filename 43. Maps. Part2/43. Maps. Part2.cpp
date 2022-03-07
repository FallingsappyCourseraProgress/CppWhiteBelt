#include <iostream>
#include <map>
#include <vector>
using namespace std;

void PrintMap(const map<string, int>& m)
{
    cout << "Size: " << m.size() << endl;

    for (const auto& item : m)
    {
        cout << item.first << ": " << item.second << endl;
    }
}

int main()
{
    map<string, int> m = { { "one", 1}, {"two", 2}, {"three", 3}};
    PrintMap(m);

    m.erase("three");
    PrintMap(m);

    vector<string> words = { "one", "two", "three", "two" };
    map<string, int> counters; 

    for (const string& word : words)
    {
        PrintMap(counters);
        counters[word]++;
    }

    PrintMap(counters);

    map<string, int> count;
    count["a"];
    PrintMap(count);

    vector<string> wordsToGroup = { "one", "two", "three" };
    map<char, vector<string>> groupedWords;

    for (const string& word : words)
    {
        groupedWords[word[0]].push_back(word);
    }

    cout << endl;

    for (const auto& item : groupedWords)
    {
        cout << item.first << endl;

        for (const string& word : item.second)
        {
            cout << word << " ";
        }

        cout << endl;
    }

    return 0;
}
