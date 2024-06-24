#include <iostream>
#include <vector>

using namespace std;

namespace reverseStr
{
    void reverseString(vector<char> &s)
    {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    int main()
    {
        vector<char> s = {'H', 'E', 'L', 'L', 'O'};
        reverseString(s);

        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i] << " ";
        }
    }
}
