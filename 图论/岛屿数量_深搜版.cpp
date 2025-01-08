#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    for (vector<int> d : dir)
    {
        int nextX = x + d[0];
        int nextY = y + d[1];

        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
        {
            continue;
        }

        if (!visited[nextX][nextY] && grid[nextX][nextY] == 1)
        {
            visited[nextX][nextY] = true;
            dfs(grid, visited, nextX, nextY);
        }
    }
}

int main()
{
    int M = 4;
    int N = 5;
    vector<vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}};
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    int result = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                visited[i][j] = true;
                result++;
                dfs(grid, visited, i, j);
            }
        }
    }

    cout << result;
}