#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(vector<list<int>> graph, int m, int n)
{
    if (m == n)
    {
        result.push_back(path);
        return;
    }

    for (int i : graph[m])
    {
        path.push_back(i);
        dfs(graph, i, n);
        path.pop_back();
    }
}

int main()
{
    int M = 5;
    int N = 5;
    vector<list<int>> graph(M + 1);
    vector<vector<int>> side = {{1, 3}, {3, 5}, {1, 2}, {2, 4}, {4, 5}};

    for (vector<int> s : side)
    {
        graph[s[0]].push_back(s[1]);
    }

    path.push_back(1);
    dfs(graph, 1, N);

    for (vector<int>& re : result)
    {
        for (int r : re)
        {
            cout << r << ' ';
        }

        cout << "\n";
    }
}