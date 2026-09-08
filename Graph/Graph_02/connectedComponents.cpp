#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(int temp, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[temp] = true;

        for (auto x : adj[temp])
        {
            if (visited[x] == false)
            {
                DFS(x, visited, adj);
            }
        }
    }

    void getAdj(vector<vector<int>> &edges, vector<vector<int>> &adj)
    {
        for (auto x : edges)
        {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        getAdj(edges, adj);

        vector<bool> visited(V, false);

        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                DFS(i, visited, adj);
                count++;
            }
        }

        return count;
    }
};