#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

public:

    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), cmp);

        for (int i = 0; i < nums.size(); i++)
        {
            if (k > 0 && nums[i] < 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }

        if (k % 2 == 1)
        {
            nums[nums.size() - 1] = - nums[nums.size() - 1];
        }

        int result = 0;

        for (int num : nums)
        {
            result += num;
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {2, -3, -1, 5, -4};
    int k = 2;

    Solution solution;
    int result = solution.largestSumAfterKNegations(nums, k);
    cout << result;
}