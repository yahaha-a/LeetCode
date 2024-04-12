#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> nums)
{
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); i++)
    {
        sort(nums.begin(), nums.end());

        if (nums[i] > 0)
        {
            break;
        }

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while (right > left)
        {
            if (nums[i] + nums[left] + nums[right] == 0)
            {
                result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                while (nums[left] == nums[left + 1])
                {
                    left++;
                }
                while (nums[right] == nums[right - 1])
                {
                    right--;
                }

                left++;
                right--;
            }
            else if (nums[i] + nums[left] + nums[right] < 0)
            {
                left++;
                continue;
            }
            else if (nums[i] + nums[left] + nums[right] > 0)
            {
                right--;
                continue;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    vector<vector<int>> results = threeSum(nums);

    for (vector<int> result : results)
    {
        for (int t : result)
        {
            cout << t << "\t";
        }

        cout << "\n";
    }
}