#include <iostream>
#include <vector>

using namespace std;

int RemoveElement(vector<int> &nums, int target)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == target)
        {
            for (int j = i + 1; j < size; j++)
            {
                nums[j - 1] = nums[j];
            }

            i--;
            size--;
        }
    }

    return size;
}

int main()
{
    vector<int> nums = {1, 2, 2, 5, 2};
    int target = 2;
    cout << RemoveElement(nums, target);
}