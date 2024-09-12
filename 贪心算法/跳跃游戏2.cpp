#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    int jump(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }

        int curDistance = 0;
        int nextDistance = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            nextDistance = max(nums[i] + i, nextDistance);

            if (i == curDistance)
            {
                ans++;
                curDistance = nextDistance;
                if (nextDistance >= nums.size() - 1)
                {
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution solution;
    int result = solution.jump(nums);

    cout << result;
}