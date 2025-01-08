#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    if (visited[x][y])
    {
        return;
    }

    visited[x][y] = true;

    for (vector<int> d : dir)
    {
        int nextX = x + d[0];
        int nextY = y + d[1];

        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
        {
            continue;
        }

        if (!visited[nextX][nextY] && grid[x][y] >= grid[nextX][nextY])
        {
            dfs(grid, visited, nextX, nextY);
        }
    }
}

bool ifResult(vector<vector<int>>& grid, int x, int y)
{
    bool resultFirst = false;
    bool resultSecond= false;

    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    dfs(grid, visited, x, y);

    for (int i = 0; i < grid.size(); i++)
    {
        if (visited[i][0])
        {
            resultFirst = true;
        }

        if (visited[i][grid[0].size() - 1])
        {
            resultSecond = true;
        }
    }

    for (int i = 0; i < grid[0].size(); i++)
    {
        if (visited[0][i])
        {
            resultFirst = true;
        }

        if (visited[grid.size() - 1][i])
        {
            resultSecond = true;
        }
    }

    return resultFirst && resultSecond;
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1, 2, 4}, {1, 2, 1, 3, 2}, {2, 4, 7, 2, 1}, {4, 5, 6, 1, 1}, {1, 4, 1, 2, 1}};

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (ifResult(grid, i, j))
            {
                cout << i << ' ' << j << '\n';
            }
        }
    }
}