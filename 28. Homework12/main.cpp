#include <iostream>
#include <vector>
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

vector<string> PalindromFilter(vector<string> words, int minLength)
{
    vector<string> filteredWords;

    for (auto word : words)
    {
        if (IsPalindrom(word) && word.length() >= minLength)
        {
            filteredWords.push_back(word);
        }
    }

    return filteredWords;
}

int main()
{
    vector<string> words, filteredWords;

    words = { "weew", "bro", "code"};
    bool isLast = false;

    filteredWords = PalindromFilter(words, 4);

    for (int i = 0; i < filteredWords.size(); i++)
    {
        if (i == (filteredWords.size() - 1))
        {
            isLast = true;
        }

        cout << filteredWords[i] << (isLast ? "" : ", ");
    }

    return 0;
}
