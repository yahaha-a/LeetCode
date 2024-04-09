#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int> nums)
{
    vector<int> result(nums.size(), 0);
    int k = result.size() - 1;

    for (int i = 0, j = nums.size() - 1; i <= j;)
    {
        if (nums[i] * nums[i] >= nums[j] * nums[j])
        {
            result[k] = nums[i] * nums[i];
            k--;
            i++;
        }
        else
        {
            result[k] = nums[j] * nums[j];
            k--;
            j--;
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {-3, -1, 0, 1, 3, 4, 7};
    nums = sortedSquares(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}