#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int maxSubArray(vector<int>& nums)
    {
        int maxNum = INT_MIN;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if (count > maxNum)
            {
                maxNum = count;
            }
            if (count < 0)
            {
                count = 0;
            }
        }

        return maxNum;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -7, 4};
    Solution solution;
    int result = solution.maxSubArray(nums);
    cout << result;
}