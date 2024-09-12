#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    int findContentChildren(vector<int> g, vector<int> s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int index = s.size() - 1;
        int result = 0;

        for (int i = g.size() - 1; i >= 0; i--)
        {
            if (index >= 0 && g[i] < s[index])
            {
                result++;
                index--;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> g = {1, 2, 7, 10};
    vector<int> s = {1, 3, 5, 9};

    Solution solution;

    int result = solution.findContentChildren(g, s);
    cout << result;
}