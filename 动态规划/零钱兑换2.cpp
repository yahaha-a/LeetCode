#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int coinChange(vector<int> coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        return dp.back();
    }
};

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution solution;
    int result = solution.coinChange(coins, amount);
    cout << result;
}