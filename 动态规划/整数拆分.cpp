#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int integerBreak(int n)
    {
        vector<int> dp(n + 1);

        dp[2] = 1;

        for (int i = 3; i < n + 1; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution solution;
    int result = solution.integerBreak(10);
    cout << result;
}