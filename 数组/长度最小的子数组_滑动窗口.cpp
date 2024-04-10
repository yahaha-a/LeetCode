#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(vector<int> nums, int target)
{
    int result = INT32_MAX;
    int subArrayLen = 0;
    int subArraySum = 0;
    int i = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        subArraySum += nums[j];

        while (subArraySum >= target)
        {
            subArrayLen = j - i + 1;
            result = result > subArrayLen ? subArrayLen : result;
            subArraySum -= nums[i];
            i++;
        }
    }

    result = result == INT32_MAX ? 0 : result;

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int target = 14;

    cout << minSubArrayLen(nums, target);
}