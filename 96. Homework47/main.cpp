#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    return "";
}

class TimeServer {
public:
    string GetCurrentTime() {
        try
        {
            auto currentTime = AskTimeServer();

            if (!currentTime.empty())
            {
                last_fetched_time = currentTime;

                return last_fetched_time;
            }
        }
        catch (system_error& e)
        {
            return last_fetched_time;
        }
        catch (const std::exception&)
        {
            throw;
        }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}