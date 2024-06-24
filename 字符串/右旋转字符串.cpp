#include <iostream>
#include <algorithm>

using namespace std;

void rightRotateStr(string &s, int n)
{
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
}

int main()
{
    string s = "abcdefg";
    int n = 2;
    rightRotateStr(s, n);

    cout << s;
}