#include <iostream>
#include <string>
#include <map>
using namespace std;


map<char, int> BuildCharCounters(string word)
{
    map<char, int> charCounter;

    for (auto c : word)
    {
        charCounter[c]++;
    }

    return charCounter;
}

bool IsAnagram(string firstWord, string secondWord)
{
    return BuildCharCounters(firstWord) == BuildCharCounters(secondWord);
}

int main()
{
    int wordPairsCount;

    cin >> wordPairsCount;

    for (int i = 0; i < wordPairsCount; i++)
    {
        string firstWord, secondWord;

        cin >> firstWord >> secondWord;

        if (IsAnagram(firstWord, secondWord))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
