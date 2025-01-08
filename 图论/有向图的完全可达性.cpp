#include <iostream>
#include <vector>
#include <list>

using namespace std;

void dfs(vector<list<int>>& graph, vector<bool>& visited, int key)
{
    visited[key] = true;
    list<int> keys = graph[key];
    for (int i : keys)
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
        }
    }
}

int main()
{
    int M = 4;
    int N = 4;
    vector<list<int>> graph(N + 1);
    vector<bool> visited(M + 1, false);

    vector<vector<int>> input = {{1, 2}, {2, 1}, {1, 3}, {2, 4}};
    for (int i = 1; i < graph.size(); i++)
    {
        for (vector<int> j : input)
        {
            if (i == j[0])
            {
                graph[i].push_back(j[1]);
            }
        }
    }

    dfs(graph, visited, 1);

    for (int i = 1; i < visited.size(); i++)
    {
        if (visited[i] == false)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << 1 << endl;
}