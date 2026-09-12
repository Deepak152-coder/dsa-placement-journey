#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void BFS(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dist)
    {
        visited[src] = 1;
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (q.size())
        {
            int temp = q.front();
            q.pop();

            for (int i = 0; i < adj[temp].size(); i++)
            {
                if (visited[adj[temp][i]] == 1)
                {
                    continue;
                }

                visited[adj[temp][i]] = 1;
                q.push(adj[temp][i]);
                dist[adj[temp][i]] = dist[temp] + 1;
            }
        }
    }

    void makeAdj(vector<vector<int>> &edges, vector<vector<int>> &adj)
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

    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
    {
        vector<vector<int>> adj(V);

        makeAdj(edges, adj);

        vector<bool> visited(V, 0);
        vector<int> dist(V, -1);

        BFS(src, adj, visited, dist);

        return dist[dest];
    }
};

int main()
{
    int V = 6;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3},
        {3, 4},
        {4, 5}};

    int src = 0;
    int dest = 5;

    Solution obj;

    int ans = obj.shortestPath(V, edges, src, dest);

    cout << "Shortest path from " << src << " to " << dest << " = " << ans << endl;

    return 0;
}