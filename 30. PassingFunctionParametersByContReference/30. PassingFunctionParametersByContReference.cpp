#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Person
{
    string name;
    string surname;
    int age;
};

vector<Person> GetMoscowPopulation()
{
    vector<Person> moscowCitizens;
    moscowCitizens.push_back({ "Ivan", "Ivanov", 25 });

    return moscowCitizens;
};

void PrintPopulationSize(const vector<Person>& p)
{
    cout << "There are " << p.size() << " people in Moscow" << endl;

    // not allowed
    //p.push_back({ "Ivan", "Ivanov", 25 });
}

int main()
{
    vector<Person> staff;

    staff.push_back({ "Ivan", "Ivanov", 25 });

    auto start = steady_clock::now();
    vector<Person> people = GetMoscowPopulation();
    auto finish = steady_clock::now();
    cout << "GetMoscowPopulation " << duration_cast<milliseconds>(finish - start).count() << "ms" << endl;

    start = steady_clock::now();
    PrintPopulationSize(people);
    finish = steady_clock::now();
    cout << "PrintPopulationSize " << duration_cast<milliseconds>(finish - start).count() << "ms" << endl;

    return 0;
}