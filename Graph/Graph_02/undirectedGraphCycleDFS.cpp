#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool DFS(int temp, int parent, vector<vector<int>> &adj,
             vector<bool> &visited)
    {

        visited[temp] = 1;

        int n = adj[temp].size();

        for (int i = 0; i < n; i++)
        {

            if (adj[temp][i] == parent)
            {
                continue;
            }

            if (visited[adj[temp][i]] == 1)
            {
                return 1;
            }

            if (DFS(adj[temp][i], temp, adj, visited))
            {
                return 1;
            }
        }

        return 0;
    }

    void makeAdj(vector<vector<int>> &edges,
                 vector<vector<int>> &adj)
    {

        int E = edges.size();

        for (int i = 0; i < E; i++)
        {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        vector<bool> visited(V, 0);

        makeAdj(edges, adj);

        for (int i = 0; i < V; i++)
        {

            if (visited[i] == 0)
            {

                if (DFS(i, -1, adj, visited))
                {
                    return 1;
                }
            }
        }

        return 0;
    }
};