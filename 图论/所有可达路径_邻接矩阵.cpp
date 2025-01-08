#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(vector<vector<int>>& graph, int m, int n)
{
    if (m == n)
    {
        result.push_back(path);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (graph[m][i] == 1)
        {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}

int main()
{
    int N = 5;
    int M = 5;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> side = {{1, 3}, {3, 5}, {1, 2}, {2, 4}, {4, 5}};

    for (vector<int> i : side)
    {
        graph[i[0]][i[1]] = 1;
    }

    path.push_back(1);
    dfs(graph, 1, 5);

    for (vector<int>& re : result)
    {
        for (int r : re)
        {
            cout << r << ' ';
        }

        cout << "\n";
    }
}