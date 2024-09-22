#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int climbStairs(int n)
    {
        if (n < 1)
        {
            return n;
        }

        vector<int> ver(n + 1);

        ver[1] = 1;
        ver[2] = 2;

        for (int i = 3; i < ver.size(); i++)
        {
            ver[i] = ver[i - 1] + ver[i - 2];
        }

        return ver[n];
    }
};

int main()
{
    Solution solution;
    int result = solution.climbStairs(5);
    cout << result;
}