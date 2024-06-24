#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseString(vector<char> &s, int k)
{
    for (int i = 0; i < s.size(); i += (2 * k))
    {
        if (i + k <= s.size())
        {
            reverse(s.begin() + i, s.begin() + i + k);
        }
        else
        {
            reverse(s.begin() + i, s.end());
        }
    }
}

int main()
{
    vector<char> s = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    reverseString(s, 3);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
}