#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int Q, lastRouteIndex = 0;
	map<int, vector<string>> busRoutes;

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int stopsCount;
		bool isShouldAdd = true;

		cin >> stopsCount;

		vector<string> stops(stopsCount);

		for (auto &s : stops)
		{
			cin >> s;
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