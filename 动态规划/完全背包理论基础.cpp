#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int CompletePack(vector<int> weight, vector<int> value, int bagWeight)
    {
        vector<int> dp(bagWeight + 1, 0);

        for (int i = 0; i < weight.size(); i++)
        {
            for (int j = weight[i]; j <= bagWeight; j++)
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }

        return dp.back();
    }
};

int main()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    Solution solution;
    int result = solution.CompletePack(weight, value, bagWeight);
    cout << result;
}