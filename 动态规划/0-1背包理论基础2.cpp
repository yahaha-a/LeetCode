#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int bag(vector<int>& weight, vector<int>& value, int backPackWeight)
    {
        vector<int> bp(backPackWeight + 1, 0);

        for (int i = 0; i < weight.size(); i++)
        {
            for (int j = backPackWeight; j >= weight[i]; j--)
            {
                bp[j] = max(bp[j], bp[j - weight[i]] + value[i]);
            }
        }

        return bp.back();
    }
};

int main()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int backPackWeight = 4;

    Solution solution;
    int result = solution.bag(weight, value, backPackWeight);
    cout << result;
}