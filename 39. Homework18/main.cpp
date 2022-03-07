#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

enum class QueueState
{
	Quiet,
	Worry
};

enum class Operation
{
	WORRY,
	QUIET,
	COME,
	WORRY_COUNT
};

class PersonInQueue
{
public:

	PersonInQueue(QueueState state)
	{
		State = state;
	}

	void SetState(QueueState newState)
	{
		State = newState;
	}

	QueueState State;
};



void PrintWorryCount(const vector<PersonInQueue>& queue)
{
	int worryCount = 0;
	
	for (auto p : queue)
	{
		if (p.State == QueueState::Worry)
		{
			worryCount++;
		}
	}

	cout << worryCount << endl;
}

void ChangeQueue(vector<PersonInQueue>& queue, int amount)
{
	if (amount > 0)
	{
		auto c = PersonInQueue(QueueState::Quiet);

		queue.resize(queue.size() + amount, c);
	}
	else
	{
		for (int i = 0; i < abs(amount); i++)
		{
			queue.pop_back();
		}
	}
}

void SetStateInQueue(vector<PersonInQueue>& queue, int index, QueueState state)
{
	queue[index].SetState(state);
}

int main()
{
	vector<PersonInQueue> queue;

	string combinedInput;
	string operationInput;
	int operationQuantity = 0;
	int amountOfOperation = 0;
	Operation parsedOperation;

	map<string, Operation> allowedOperations =
	{
		{ "WORRY", Operation::WORRY },
		{ "QUIET", Operation::QUIET },
		{ "COME", Operation::COME },
		{ "WORRY_COUNT", Operation::WORRY_COUNT }
	};

	cin >> operationQuantity;

	for (int i = 0; i <= operationQuantity; i++)
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
			amountOfOperation = stoi(input[1]);
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
		case Operation::WORRY:
			SetStateInQueue(queue, amountOfOperation, QueueState::Worry);
			break;
		case Operation::COME:
			ChangeQueue(queue, amountOfOperation);
			break;
		case Operation::QUIET:
			SetStateInQueue(queue, amountOfOperation, QueueState::Quiet);
			break;
		case Operation::WORRY_COUNT:
			PrintWorryCount(queue);
			break;
		default:
			break;
		}
	}


    return 0;
}
