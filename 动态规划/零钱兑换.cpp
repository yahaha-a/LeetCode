#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int change(vector<int> coins, int amount)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp.back();
    }
};

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    Solution solution;
    int result = solution.change(coins, amount);
    cout << result;
}