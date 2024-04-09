#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortedSquares(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] *= nums[i];
    }

    sort(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums = {5, 1, 4, 3, 5};
    sortedSquares(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}