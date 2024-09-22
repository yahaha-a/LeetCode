#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int bag(vector<int>& weight, vector<int>& value, int backPackWeight)
    {
        vector<vector<int>> bp(weight.size(), vector<int>(backPackWeight + 1, 0));

        for (int i = weight[0]; i < backPackWeight + 1; i++)
        {
            bp[0][i] = value[0];
        }

        for (int i = 1; i < weight.size(); i++)
        {
            for (int j = 0; j < backPackWeight + 1; j++)
            {
                if (j < weight[i])
                {
                    bp[i][j] = bp[i - 1][j];
                }
                else
                {
                    bp[i][j] = max(bp[i - 1][j], bp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }

        return bp[weight.size() - 1][backPackWeight];
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