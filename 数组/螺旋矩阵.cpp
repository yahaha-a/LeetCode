#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> SpiralMatrix(int n)
{
    vector<vector<int>> nums(n, vector<int>(n, 0));
    int loop = n / 2;
    int startX = 0;
    int startY = 0;
    int offset = 1;
    int count = 1;

    while(loop--)
    {
        int i = startX;
        int j = startY;

        for (; j < n - offset; j++)
        {
            nums[i][j] = count++;
        }

        for (; i < n - offset; i++)
        {
            nums[i][j] = count++;
        }

        for (; j > startY; j--)
        {
            nums[i][j] = count++;
        }

        for (; i > startX; i--)
        {
            nums[i][j] = count++;
        }

        startX++;
        startY++;
        offset++;
    }

    if (n % 2 == 1)
    {
        nums[startX][startY] = count;
    }

    return nums;
}

int main()
{
    int n = 5;
    vector<vector<int>> nums = SpiralMatrix(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << "\t";
        }

        cout << "\n";
    }
}