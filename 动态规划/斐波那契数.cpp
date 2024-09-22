#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int fib(int N)
    {
        if (N < 1)
        {
            return N;
        }

        vector<int> fib(N + 1);

        fib[0] = 0;
        fib[1] = 1;

        for (int i = 2; i < fib.size(); i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        return fib[N];
    }
};

int main()
{
    Solution solution;
    int result = solution.fib(4);
    cout << result;
}