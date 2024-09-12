#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }

        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> que;

        for (int i = 0; i < people.size(); i++)
        {
            int position = people[i][1];
            que.insert(que.begin() + position, people[i]);
        }

        return que;
    }
};

int main()
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

    Solution solution;

    vector<vector<int>> result = solution.reconstructQueue(people);

    for (vector<int> r : result)
    {
        cout << "[";
        for (int i : r)
        {
            cout << i << " ";
        }
        cout << "]";
    }
}