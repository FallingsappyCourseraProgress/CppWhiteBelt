#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> result;

    do   
    {
        result.push_back(N % 2);
        //cout << N % 2;
        N /= 2;
    } while (N != 0);

    string s;

    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i];
    }

    return 0;
}
