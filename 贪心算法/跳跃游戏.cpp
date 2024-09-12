#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    bool canJump(vector<int>& nums)
    {
        int cover = 0;
        if (nums.size() == 1)
        {
            return true;
        }

        for (int i = 0; i < cover; i++)
        {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution solution;
    bool result = solution.canJump(nums);

    if (result)
    {
        cout << "能";
    }
    else
    {
        cout << "不能";
    }
}