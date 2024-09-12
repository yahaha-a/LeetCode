#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &s, int value)
{
    int slowIndex = 0;

    for (int fastIndex = 0; fastIndex < s.size(); fastIndex++)
    {
        if (value != s[fastIndex])
        {
            s[slowIndex++] = s[fastIndex];
        }
    }

    return slowIndex;
}

int main()
{
    vector<int> s = {1, 3, 4, 3, 2, 3};
    int value = 3;

    int index = removeElement(s, value);

    for (int i = 0; i < value; i++)
    {
        cout << s[i] << " ";
    }
}