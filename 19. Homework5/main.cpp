#include <iostream>

using namespace std;

int main()
{
    float N, A, B, X, Y;

    cin >> N >> A >> B >> X >> Y;

    if (A >= B)
    {
        return 0;
    }

    if (N > A && N <= B)
    {
        N -= N * (X / 100);
    }
    else if (N > B)
    {
        N -= N * (Y / 100);
    }

    cout << N;

    return 0;
}
