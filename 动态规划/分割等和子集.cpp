#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    bool canPartition(vector<int>& nums)
    {
        vector<int> bp(10001, 0);

        int sum;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        int target;
        if (sum % 2 == 1)
        {
            return false;
        }
        else
        {
            target = sum / 2;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                bp[j] = max(bp[j], bp[j - nums[i]] + nums[i]);
            }
        }

        if (bp[target] == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    vector<int> nums = {1, 5, 11, 5};

    Solution solution;
    bool result = solution.canPartition(nums);

    if (result)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}