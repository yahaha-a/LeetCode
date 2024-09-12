#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }

public:

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= result.back()[1])
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    Solution solution;
    vector<vector<int>> result = solution.merge(intervals);

    for (vector<int> re : result)
    {
        cout << "[";

        for (int i = 0; i < re.size(); i++)
        {
            cout << re[i];
            if (i != re.size() - 1)
            {
                cout << ", ";
            }
        }
        
        cout << "]";
    }
}