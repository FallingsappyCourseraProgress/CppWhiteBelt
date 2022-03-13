#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
	int Q, lastRouteIndex = 0;
	map<int, set<string>> busRoutes;

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int stopsCount;
		bool isShouldAdd = true;

		cin >> stopsCount;

		set<string> stops;

		for (size_t i = 0; i < stopsCount; i++)
		{
			string s;

			cin >> s;
			stops.insert(s);
		}

		for (int i = 0; i < busRoutes.size(); i++)
		{
			if (busRoutes[i] == stops)
			{
				cout << "Already exists for " << i + 1 << endl;

				isShouldAdd = false;
			}
		}

		if (isShouldAdd)
		{
			busRoutes[lastRouteIndex] = stops;
			cout << "New bus " << ++lastRouteIndex << endl;
		}
	}

	return 0;
}