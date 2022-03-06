#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string word)
{
    string resultingWord = "";

    for (int i = word.size() - 1; i >= 0; i--)
    {
        resultingWord += word[i];
    }
    
    if (word == resultingWord)
    {
        return true;
    }

    return false;
}

int main()
{
    string word;

    cin >> word;

    cout << IsPalindrom(word) ? "true" : "false";

    return 0;
}
