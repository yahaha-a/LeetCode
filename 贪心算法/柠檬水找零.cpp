#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    bool lemonadeChange(vector<int>& nums)
    {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 5)
            {
                five++;
            }

            if (nums[i] == 10)
            {
                if (five > 0)
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
            }

            if (nums[i] == 20)
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                    twenty++;
                }
                else if (five >= 3)
                {
                    five -= 3;
                    twenty++;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<int> nums = {5, 5, 10, 10, 20};
    Solution solution;
    bool result = solution.lemonadeChange(nums);

    if (result)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}