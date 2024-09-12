#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        int curDiff = 0;
        int preDiff = 0;
        int result = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            curDiff = nums[i + 1] - nums[i];

            if (preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0)
            {
                result++;
                preDiff = curDiff;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};

    Solution solution;
    int result = solution.wiggleMaxLength(nums);
    cout << result;
}