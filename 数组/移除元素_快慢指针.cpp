#include <iostream>
#include <vector>

using namespace std;

int RemoveElement(vector<int> &nums, int target)
{
    int slowIndex = 0;

    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        if (target != nums[fastIndex])
        {
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
    }

    return slowIndex;
}

int main()
{
    vector<int> nums = {1, 2, 2, 5, 3, 2};
    int target = 2;
    cout << RemoveElement(nums, target);
}