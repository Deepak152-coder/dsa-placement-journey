#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool BFS(int start, vector<vector<int>> &adj,
             vector<bool> &visited)
    {

        queue<pair<int, int>> q;

        visited[start] = 1;
        q.push({start, -1});

        while (q.size())
        {

            int temp = q.front().first;
            int parent = q.front().second;

            q.pop();

            int n = adj[temp].size();

            for (int i = 0; i < n; i++)
            {

                if (parent == adj[temp][i])
                {
                    continue;
                }

                if (visited[adj[temp][i]] == 1)
                {
                    return 1;
                }

                visited[adj[temp][i]] = 1;

                q.push({adj[temp][i], temp});
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

        makeAdj(edges, adj);

        vector<bool> visited(V, 0);

        for (int i = 0; i < V; i++)
        {

            if (visited[i] == 0)
            {

                if (BFS(i, adj, visited))
                {
                    return 1;
                }
            }
        }

        return 0;
    }
};