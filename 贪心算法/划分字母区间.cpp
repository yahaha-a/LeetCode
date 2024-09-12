#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:

    vector<int> partitionLabels(string s)
    {
        int hash[27] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }

        int left = 0;
        int right = 0;
        vector<int> result;

        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, hash[s[i] - 'a']);
            if (i == right)
            {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        
        return result;
    }
};

int main()
{
    string s = "ababcbacadefegdehijhklij";
    Solution solution;
    vector<int> result = solution.partitionLabels(s);

    for (int i = 0; i < result.size(); i++)
    {
        cout << i << " ";
    }
}