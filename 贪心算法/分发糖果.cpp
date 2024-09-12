#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:


    int candy(vector<int>& ratings)
    {
        vector<int> candyNum(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candyNum[i] = candyNum[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candyNum[i] = max(candyNum[i], candyNum[i + 1] + 1);
            }
        }

        int result = 0;
        for (int i = 0; i < candyNum.size(); i++)
        {
            result += candyNum[i];
        }

        return result;
    }
};

int main()
{
    vector<int> ratings = {1, 2, 2, 5, 4, 3, 2};
    Solution solution;
    int result = solution.candy(ratings);
    cout << result;
}