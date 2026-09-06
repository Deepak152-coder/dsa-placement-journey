#include <bits/stdc++.h>
using namespace std;

void DFS(int temp, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans)
{
    visited[temp] = 1;
    ans.push_back(temp);

    int n = adj[temp].size();

    for (int i = 0; i < n; i++)
    {
        if (visited[adj[temp][i]] == 0)
        {
            DFS(adj[temp][i], adj, visited, ans);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj)
{
    int v = adj.size();

    vector<int> ans;
    vector<bool> visited(v, 0);

    DFS(0, adj, visited, ans);

    return ans;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    for (int i = 0; i < e; i++)
    {
        int u, w;
        cin >> u >> w;

        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    vector<int> ans = dfs(adj);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}