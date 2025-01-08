#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    visited[x][y] = true;

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

void dfsN(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    visited[x][y] = true;
    grid[x][y] = 0;
    
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
            grid[nextX][nextY] = 0;
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

    for (int i = 0; i < M; i++)
    {
        if (!visited[i][0] && grid[i][0] == 1)
        {
            dfs(grid, visited, i, 0);
        }
        if (!visited[i][N - 1] && grid[i][N - 1] == 1)
        {
            dfs(grid, visited, i, N - 1);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[0][i] && grid[0][i] == 1)
        {
            dfs(grid, visited, 0, i);
        }
        if (!visited[M - 1][i] && grid[M - 1][i] == 1)
        {
            dfs(grid, visited, M - 1, i);
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                dfsN(grid, visited, i, j);
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}