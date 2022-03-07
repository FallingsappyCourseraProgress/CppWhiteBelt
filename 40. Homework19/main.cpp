#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int GetNumberOfDays(int month)
{
	if (month == 2)
	{
		return 28;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
		return 31;
	else
		return 30;
}

enum class Operation
{
	ADD,
	NEXT,
	DUMP,
};

class Task
{
public:

	Task(string name)
	{
		Name = name;
	}

	string Name;
};

class Day
{
public:
	Day()
	{

	}

	Day(vector<Task> tasks)
	{
		Tasks = tasks;
	}

	vector<Task> Tasks;

	void Add(Task taskToAdd)
	{
		Tasks.push_back(taskToAdd);
	}

	void Dump() const
	{
		cout << Tasks.size() << " ";

		for (int i = 0; i < Tasks.size(); i++)
		{
			cout << Tasks[i].Name << " ";
		}

		cout << endl;
	}
};

void AddToDay(vector<Day>& month, int day, Task taskToAdd)
{
	if (day - 1 >= month.size())
	{
		return;
	}

	month[day - 1].Add(taskToAdd);
}

void DumpByDay(const vector<Day>& month, int day)
{
	if (day - 1 >= month.size())
	{
		cout << 0 << endl;
		return;
	}

	month[day - 1].Dump();
}

void Next(vector<Day>& month, int& monthIndex)
{
	if (monthIndex == 12)
	{
		monthIndex = 1;
	}
	else
	{
		monthIndex++;
	}

	vector<Day> nextMonth(GetNumberOfDays(monthIndex));

	if (month.size() <= nextMonth.size())
	{
		for (int i = 0; i < nextMonth.size() - month.size(); i++)
		{
			month.push_back(Day());
		}
	}
	else
	{
		for (int i = month.size() - (month.size() - nextMonth.size()); i < month.size(); i++)
		{
			if (month[i].Tasks.size() == 0)
			{
				continue;
			}

			month[nextMonth.size() - 1].Tasks.insert(end(month[nextMonth.size() - 1].Tasks), begin(month[i].Tasks), end(month[i].Tasks));
			

			if (i == 0) //for preventing unsigned wrap
				break;
		}

		month.resize(nextMonth.size());
	}
}

int main()
{
	int q;
	int monthIndex = 1;
	string combinedInput, operationInput, taskName;
	vector<Day> month(GetNumberOfDays(monthIndex));

	cin >> q;

	int day = 0;
	Operation parsedOperation;

	map<string, Operation> allowedOperations =
	{
		{ "ADD", Operation::ADD },
		{ "NEXT", Operation::NEXT },
		{ "DUMP", Operation::DUMP },
	};


	for (int i = 0; i <= q; i++)
	{
		getline(cin, combinedInput);

		vector<string> input;

		istringstream iss(combinedInput);

		for (string s; iss >> s;)
			input.push_back(s);

		if (input.size() == 0)
		{
			continue;
		}

		operationInput = input[0];

		if (input.size() > 1)
		{
			day = stoi(input[1]);
		}

		if (input.size() > 2)
		{
			taskName = input[2];
		}

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
			AddToDay(month, day, Task(taskName));
			break;
		case Operation::DUMP:
			DumpByDay(month, day);
			break;
		case Operation::NEXT:
			Next(month, monthIndex);
			break;
		default:
			break;
		}
	}

    return 0;
}
