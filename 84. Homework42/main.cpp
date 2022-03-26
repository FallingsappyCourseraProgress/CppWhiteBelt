#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum class Operation
{
    name,
    date,
};

struct Student
{
    string firstName;
    string lastName;

    int day;
    int month;
    int year;
};


bool IsBadRequest(const int& studentNumber, const int& n)
{
    return studentNumber < 0 || studentNumber >= n;
}

void FillStudents(vector<Student>& students, const int& n)
{
    string firstName, lastName;
    int day, month, year;

    for (size_t i = 0; i < n; ++i) {
        cin >> firstName >> lastName >> day >> month >> year;

        students.push_back(Student{
          firstName,
          lastName,
          day,
          month,
          year
        });
    }
}

void MakeQueries(vector<Student>& students, const int& n)
{
    int m;
    cin >> m;
    string query;
    int studentNumber;
    Operation parsedOperation;

    map<string, Operation> allowedOperations =
    {
        { "name", Operation::name },
        { "date", Operation::date },
    };

    for (int i = 0; i < m; ++i) {
        cin >> query >> studentNumber;
        --studentNumber;

        if (IsBadRequest(studentNumber, n))
        {
            cout << "bad request" << endl;
            continue;
        }

        try
        {
            parsedOperation = allowedOperations.at(query);
        }
        catch (const std::exception&)
        {
            cout << "bad request" << endl;
            continue;
        }

        switch (parsedOperation)
        {
            case Operation::name:
            {
                cout << students[studentNumber].firstName << " " << students[studentNumber].lastName << endl;
                break;
            }
            case Operation::date:
            {
                cout << students[studentNumber].day << "." << students[studentNumber].month << "." << students[studentNumber].year << endl;
                break;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<Student> students;

    FillStudents(students, n);
    MakeQueries(students, n);

    return 0;
}