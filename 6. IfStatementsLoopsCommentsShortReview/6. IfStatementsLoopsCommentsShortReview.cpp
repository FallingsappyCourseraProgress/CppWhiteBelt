#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* программа для подсчета
   суммы элементов вектора */

int main()
{
    int x = 4;
    int y = 5;

    if (x == y)
    {
        cout << "equal" << endl;
    }
    else
    {
        cout << "not equal" << endl;
    }


    // vector which elements will be summarized
    vector<int> nums = { 1, 2, 3 };
    for (auto x : nums)
    {

    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    cout << sum << endl;

    int i = 0;
    sum = 0;
    while (i < nums.size())
    {
        sum += nums[i];
        i += 1;
    }

    cout << sum << endl;

    return 0;
}
