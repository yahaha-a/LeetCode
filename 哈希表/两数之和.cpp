#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    unordered_map<int, int> nums_map;

    for (int i = 0; i < nums.size(); i++)
    {
        auto num = nums_map.find(target - nums[i]);
        if (num != nums_map.end())
        {
            return {num->second, i};
        }
        else
        {
            nums_map.insert(pair<int, int>(nums[i], i));
        }
    }

    return {};
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    vector<int> results = twoSum(nums, target);

    for (int result : results)
    {
        cout << result << " ";
    }
}