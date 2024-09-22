#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int combinationSum4(vector<int> nums, int target)
    {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i >= nums[j])
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp.back();
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    int target = 4;

    Solution solution;
    int result = solution.combinationSum4(nums, target);
    cout << result;
}