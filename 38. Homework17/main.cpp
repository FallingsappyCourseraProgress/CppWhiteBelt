#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    int amountOfConsecutiveDays;
    cin >> amountOfConsecutiveDays;

    vector<int> dayTemperatures(amountOfConsecutiveDays);

    int sum = 0;

    for (int i = 0; i < dayTemperatures.size(); i++)
    {
        cin >> dayTemperatures[i];
        sum += dayTemperatures[i];
    }

    int average = sum / dayTemperatures.size();

    vector<int> moreThenAverage;

    for (int i = 0; i < dayTemperatures.size(); i++)
    {
        if (dayTemperatures[i] > average)
        {
            moreThenAverage.push_back(i);
        }
    }

    cout << moreThenAverage.size() << endl;
    PrintVector(moreThenAverage);

    return 0;
}