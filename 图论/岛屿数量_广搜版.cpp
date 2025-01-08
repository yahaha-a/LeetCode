#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;

    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();
        for (vector<int> d : dir)
        {
            int nextX = cur.first + d[0];
            int nextY = cur.second + d[1];

            if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
            {
                continue;
            }

            if (!visited[nextX][nextY] && grid[nextX][nextY] == 1)
            {
                que.push({nextX, nextY});
                visited[nextX][nextY] = true;
            }
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
                result++;
                bfs(grid, visited, i, j);
            }
        }
    }

    cout << result;
}