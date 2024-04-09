#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(vector<int> nums, int target)
{
    int result = INT32_MAX;
    int subArrayLen = 0;
    int subArraySum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j <= nums.size(); j++)
        {
            subArraySum = 0;
            for (int k = i; k < j; k++)
            {
                subArraySum += nums[k];
            }

            if (subArraySum >= target)
            {
                subArrayLen = j - i;
                result = result > subArrayLen ? subArrayLen : result;
            }
        }
    }

    return result == INT32_MAX ? 0 : result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int target = 14;

    cout << minSubArrayLen(nums, target);
}