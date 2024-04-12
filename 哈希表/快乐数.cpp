#include <iostream>
#include <unordered_set>

using namespace std;

int getSum(int n)
{
    int sum = 0;

    while (n)
    {
        sum += (n % 10) * (n % 10);
        n = n / 10;
    }

    return sum;
}

bool isHappy(int n)
{
    unordered_set<int> nums_set;

    while (true)
    {
        int sum = getSum(n);

        if (sum == 1)
        {
            return true;
        }
        else
        {
            if (nums_set.find(sum) != nums_set.end())
            {
                return false;
            }
            else
            {
                nums_set.insert(sum);
            }
        }

        n = sum;
    }
}

int main()
{
    int n = 19;

    if (isHappy(n))
    {
        cout << "是快乐数";
    }
    else
    {
        cout << "不是快乐数";
    }
}