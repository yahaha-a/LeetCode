#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> dp(cost.size() + 1);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp.back();
    }
};

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution solution;
    int result = solution.minCostClimbingStairs(cost);
    cout << result;
}