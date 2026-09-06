#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj)
{
    int v = adj.size();

    queue<int> q;
    vector<bool> visited(v, 0);

    q.push(0);
    visited[0] = 1;

    vector<int> ans;

    while (q.size())
    {
        int temp = q.front();
        q.pop();

        ans.push_back(temp);

        int m = adj[temp].size();

        for (int i = 0; i < m; i++)
        {
            if (visited[adj[temp][i]] == 0)
            {
                visited[adj[temp][i]] = 1;
                q.push(adj[temp][i]);
            }
        }
    }

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

    vector<int> ans = bfs(adj);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}