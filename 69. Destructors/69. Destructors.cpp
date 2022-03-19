#include <iostream>
#include <vector>
using namespace std;

int ComputeDistance(const string& source, const string& destination)
{
	return source.length() - destination.length();
}

class Route
{
public:
	Route()
	{
		source = "Moscow";
		destination = "Saint Petersburg";
		UpdateLength();
	}

	Route(const string& newSource, const string& newDestination)
	{
		source = newSource;
		destination = newDestination;
		UpdateLength();
	}

	~Route()
	{
		for (const string& entry : computeDistanceLog)
		{
			cout << entry << endl;
		}
	}

	string GetSource() const
	{
		return source;
	}

	string GetDestination() const
	{
		return destination;
	}

	int GetLength()
	{
		return length;
	}

	void SetSource(const string& newSource)
	{
		source = newSource;
		UpdateLength();
	}

	void SetDestination(const string& newDestination)
	{
		destination = newDestination;
		UpdateLength();
	}
private:
	void UpdateLength()
	{
		length = ComputeDistance(source, destination);
		computeDistanceLog.push_back(source + " " + destination);
	}

	string source;
	string destination;
	int length;

	vector<string> computeDistanceLog;
};

void PrintRoute(const Route& route)
{
	cout << route.GetSource() << " - " << route.GetDestination() << "\n";
}

void ReverseRoute(Route& route)
{
	string oldSource = route.GetSource();
	string oldDestination = route.GetDestination();

	route.SetSource(oldDestination);
	route.SetDestination(oldSource);
}

int main()
{
	Route route("Moscow", "Saint Petersburgh");

	route.SetSource("Vyborg");
	route.SetDestination("Vologda");

	return 0;
}
