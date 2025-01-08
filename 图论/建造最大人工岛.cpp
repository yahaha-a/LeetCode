#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
unordered_map<int, int> gridNum;

int dfs(vector<vector<int>>& grid, int x, int y, int mark)
{
    grid[x][y] = mark;
    int count = 1;

    for (vector<int> d : dir)
    {
        int nextX = x + d[0];
        int nextY = y + d[1];

        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
        {
            continue;
        }

        if (grid[nextX][nextY] == 1)
        {
            count += dfs(grid, nextX, nextY, mark);
        }
    }
    
    return count;
}

void StatisticalArea(vector<vector<int>>& grid)
{
    int mark = 2;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                int area = dfs(grid, i, j, mark);
                gridNum[mark] = area;
                mark++;
            }
        }
    }
}

int largestIsland(vector<vector<int>>& grid)
{
    int result = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                int temp = 1;
                unordered_set<int> seen;

                for (vector<int> d : dir)
                {
                    int nextX = i + d[0];
                    int nextY = j + d[1];

                    if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                    {
                        continue;
                    }

                    int mark = grid[nextX][nextY];
                    if (mark > 1 && seen.find(mark) == seen.end())
                    {
                        temp += gridNum[mark];
                        seen.insert(mark);
                    }
                }

                result = max(result, temp);
            }
        }
    }

    return result == 0 ? 1 : result;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}};

    StatisticalArea(grid);
    int result = largestIsland(grid);

    cout << result;
}
