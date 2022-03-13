#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

enum class Operation
{
    ADD,
    COUNT,
    CHECK,
};

void Add(set<vector<string>>& synonyms, map<string, unsigned int>& uniquePairCounter)
{
    string word1, word2;

    cin >> word1 >> word2;

    vector<string> wordPairs = { word1, word2 };
    vector<string> wordPairs1 = { word2, word1 };


    bool shouldIncrease = true;

    if (synonyms.find(wordPairs) != synonyms.end() || synonyms.find(wordPairs1) != synonyms.end())
    {
        shouldIncrease = false;
    }
    

    synonyms.insert({ word1, word2 });

    if (shouldIncrease)
    {
        uniquePairCounter[word1]++;
        uniquePairCounter[word2]++;
    }
}

void Count(const map<string, unsigned int>& uniquePairCounter)
{
    string word1;
    int count = 0;

    cin >> word1;

    if (uniquePairCounter.find(word1) == uniquePairCounter.end())
    {
        cout << 0 << endl;
        return;
    }

    cout << uniquePairCounter.at(word1) << endl;
}

void Check(const set<vector<string>>& synonyms)
{
    string word1, word2;

    cin >> word1 >> word2;

    vector<string> wordPairs = { word1, word2 };
    vector<string> wordPairs1 = { word2, word1 };

    if (synonyms.find(wordPairs) != synonyms.end() || synonyms.find(wordPairs1) != synonyms.end())
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main()
{
    map<string, Operation> allowedOperations =
    {
        { "ADD", Operation::ADD },
        { "COUNT", Operation::COUNT },
        { "CHECK", Operation::CHECK },
    };

    int Q;
    string operationInput;
    Operation parsedOperation;
    set<vector<string>> synonyms;
    map<string, unsigned int> uniquePairCounter;

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> operationInput;

        try
        {
            parsedOperation = allowedOperations.at(operationInput);
        }
        catch (const std::exception&)
        {
            continue;
        }

        switch (parsedOperation)
        {
        case Operation::ADD:
        {
            Add(synonyms, uniquePairCounter);
            break;
        }
        case Operation::COUNT:
        {
            Count(uniquePairCounter);
            break;
        }
        case Operation::CHECK:
        {
            Check(synonyms);
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
