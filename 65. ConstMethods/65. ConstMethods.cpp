#include <iostream>
using namespace std;

int ComputeDistance(const string& source, const string& destination)
{
	return source.length() - destination.length();
}

class Route
{
public:
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
	}

	string source;
	string destination;
	int length;
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
	Route route;
	route.SetSource("Москва");
	route.SetDestination("Вологда");
	PrintRoute(route);

	ReverseRoute(route);
	PrintRoute(route);

	return 0;
}
