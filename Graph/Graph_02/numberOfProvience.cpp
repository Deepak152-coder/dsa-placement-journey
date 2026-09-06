#include <bits/stdc++.h>
using namespace std;

void DFS(int temp, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[temp] = 1;

    int n = adj[temp].size();

    for (int i = 0; i < n; i++)
    {
        if (adj[temp][i] == 1 && visited[i] == 0)
        {
            DFS(i, adj, visited);
        }
    }
}

int findCircleNum(vector<vector<int>> &adj)
{
    int v = adj.size();

    vector<bool> visited(v, 0);
    int count = 0;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            DFS(i, adj, visited);
            count++;
        }
    }

    return count;
}

int main()
{
    int v;
    cin >> v;

    vector<vector<int>> adj(v, vector<int>(v));

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> adj[i][j];
        }
    }

    cout << findCircleNum(adj);

    return 0;
}