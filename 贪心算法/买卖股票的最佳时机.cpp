#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    int maxProfit(vector<int>& prices)
    {
        int result;

        for (int i = 1; i < prices.size(); i++)
        {
            result += max(prices[i] - prices[i - 1], 0);
        }

        return result;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 10, 3, 6, 4};
    Solution solution;
    int result = solution.maxProfit(prices);
    cout << result;
}