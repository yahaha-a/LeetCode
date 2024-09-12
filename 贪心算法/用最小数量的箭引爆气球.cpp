#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }

public:

    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), cmp);

        int result = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > points[i - 1][1])
            {
                result++;
            }
            else
            {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    Solution solution;
    int result = solution.findMinArrowShots(points);
    cout << result;
}