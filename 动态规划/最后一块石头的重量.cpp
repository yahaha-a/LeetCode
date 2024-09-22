#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int lastStoneWeightII(vector<int>& nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int target = sum / 2;

        vector<int> dp(15001, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return sum - dp[target] - dp[target];
    }
};

int main()
{
    vector<int> nums = {2, 4, 1, 1};

    Solution solution;
    int result = solution.lastStoneWeightII(nums);
    cout << result;
}