#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:

    int findMaxForm(vector<string> strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string str : strs)
        {
            int zeroNum = 0;
            int oneNum = 0;
            for (char c : str)
            {
                if (c == '0')
                {
                    zeroNum++;
                }
                if (c == '1')
                {
                    oneNum++;
                }
            }

            for (int i = m; i >= zeroNum; i--)
            {
                for (int j = n; j >= oneNum; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    Solution solution;
    int result = solution.findMaxForm(strs, 3, 3);
    cout << result;
}