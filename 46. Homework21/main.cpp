#include <iostream>
#include <map>
using namespace std;

enum class Operation
{
    CHANGE_CAPITAL,
    RENAME,
    ABOUT,
    DUMP,
};

void ChangeCapital(map<string, string>& catalog, string country, string newCapital)
{
    if (catalog.find(country) == catalog.end())
    {
        catalog[country] = newCapital;
        cout << "Introduce new country " << country << " with capital " << newCapital << endl;

        return;
    }

    if (catalog.at(country) == newCapital)
    {
        cout << "Country " << country << " hasn't changed its capital" << endl;

        return;
    }

    
    cout << "Country " << country << " has changed its capital from " << catalog.at(country) << " to " << newCapital << endl;
    catalog[country] = newCapital;
}

void Rename(map<string, string>& catalog, string oldCountryName, string newCountryName)
{
    if (catalog.find(newCountryName) != catalog.end() || oldCountryName == newCountryName || catalog.find(oldCountryName) == catalog.end())
    {
        cout << "Incorrect rename, skip" << endl;
        return;
    }

    string capitalName = catalog[oldCountryName];
    cout << "Country " << oldCountryName << " with capital " << capitalName << " has been renamed to " << newCountryName << endl;
    
    catalog.erase(oldCountryName);
    catalog[newCountryName] = capitalName;
}

void About(const map<string, string>& catalog, string country)
{
    if (catalog.find(country) == catalog.end())
    {
        cout << "Country " << country << " doesn't exist" << endl;
        return;
    }

    cout << "Country " << country << " has capital " << catalog.at(country) << endl;
}

void Dump(const map<string, string>& catalog)
{
    if (catalog.size() == 0)
    {
        cout << "There are no countries in the world" << endl;
        return;
    }

    for (auto c : catalog)
    {
        cout << c.first << '/' << c.second << " ";
    }

    cout << endl;
}

int main()
{
    int Q;
    string operationInput;
    Operation parsedOperation;
    map<string, string> capitalsCatalog;

    map<string, Operation> allowedOperations =
    {
        { "CHANGE_CAPITAL", Operation::CHANGE_CAPITAL },
        { "RENAME", Operation::RENAME },
        { "ABOUT", Operation::ABOUT },
        { "DUMP", Operation::DUMP },
    };

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
        case Operation::CHANGE_CAPITAL:
        {
            string country, newCapital;

            cin >> country >> newCapital;

            ChangeCapital(capitalsCatalog, country, newCapital);

            break;
        }
        case Operation::RENAME:
        {
            string oldCountryName, newCountryName;

            cin >> oldCountryName >> newCountryName;

            Rename(capitalsCatalog, oldCountryName, newCountryName);

            break;
        }
        case Operation::ABOUT:
        {
            string countryName;

            cin >> countryName;

            About(capitalsCatalog, countryName);

            break;
        }
        case Operation::DUMP:
            Dump(capitalsCatalog);
            break;
        default:
            break;
        }
    }

    return 0;
}
