#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }

public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);

        int end = intervals[0][1];
        int count = 1;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= end)
            {
                end = intervals[i][1];
                count++;
            }
        }

        return intervals.size() - count;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution solution;
    int result = solution.eraseOverlapIntervals(intervals);
    cout << result;
}