#include <iostream>
#include <map>
#include <vector>
using namespace std;

enum class Operation
{
    NEW_BUS,
    BUSES_FOR_STOP,
    STOPS_FOR_BUS,
    ALL_BUSES,
};

void BusesForStop(const map<string, vector<string>>& stopsForBuses, string stop)
{
    string buses;

    if (stopsForBuses.find(stop) == stopsForBuses.end())
    {
        cout << "No stop" << endl;
        return;
    }

    for (auto b : stopsForBuses.at(stop))
    {
        buses += b + " ";
    }

    cout << buses << endl;
}

void StopsForBus(const map<string, vector<string>>& busesForStop, string bus, const map<string, vector<string>> stopsForBuses)
{
    string stops;

    if (busesForStop.find(bus) == busesForStop.end())
    {
        cout << "No bus" << endl;
        return;
    }

    for (auto s : busesForStop.at(bus))
    {
        string buses;

        if (busesForStop.find(bus) == busesForStop.end())
        {
            buses = "no interchange";
        }

        for (auto b : stopsForBuses.at(s))
        {
            if (b == bus)
            {
                continue;
            }

            buses += b + " ";
        }

        if (buses.empty())
        {
            buses = "no interchange";
        }

        cout << "Stop " << s << ": " << buses << endl;
    }
}

void AllBuses(const map<string, vector<string>>& busesToStops)
{
    if (busesToStops.size() == 0)
    {
        cout << "No buses" << endl;

        return;
    }

    for (auto b : busesToStops)
    {
        string combinedRoute;

        for (auto r : b.second)
        {
            combinedRoute += r + " ";
        }

        cout << "Bus " << b.first << ": " << combinedRoute << endl;
    }
}

void NewBus(map<string, vector<string>>& busesToStops, map<string, vector<string>>& stopsToBuses)
{
    string bus;
    int stopCount;

    cin >> bus >> stopCount;

    vector<string> stops(stopCount);

    for (auto &s : stops)
    {
        cin >> s;

        stopsToBuses[s].push_back(bus);
    }

    busesToStops[bus] = stops;
}

int main()
{
    map<string, vector<string>> busesToStops;
    map<string, vector<string>> stopsForBuses;
    map<string, Operation> allowedOperations =
    {
        { "NEW_BUS", Operation::NEW_BUS },
        { "BUSES_FOR_STOP", Operation::BUSES_FOR_STOP },
        { "STOPS_FOR_BUS", Operation::STOPS_FOR_BUS },
        { "ALL_BUSES", Operation::ALL_BUSES },
    };

    int Q;
    string operationInput;
    Operation parsedOperation;

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
        case Operation::NEW_BUS:
        {
            NewBus(busesToStops, stopsForBuses);

            break;
        }
        case Operation::BUSES_FOR_STOP:
        {
            string stop;

            cin >> stop;

            BusesForStop(stopsForBuses, stop);

            break;
        }
        case Operation::STOPS_FOR_BUS:
        {
            string bus;

            cin >> bus;

            StopsForBus(busesToStops, bus, stopsForBuses);

            break;
        }
        case Operation::ALL_BUSES:
            AllBuses(busesToStops);
            break;
        default:
            break;
        }
    }

    return 0;
}
