#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M = 5;
    int N = 5;
    vector<vector<int>> grid = {{0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 1, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}};

    int sum = 0;
    int side = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 1)
            {
                sum++;
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                {
                    side++;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                {
                    side++;
                }
            }
        }
    }

    cout << sum * 4 - side * 2;
}