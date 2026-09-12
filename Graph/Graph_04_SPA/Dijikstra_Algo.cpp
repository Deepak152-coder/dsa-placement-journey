#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Dijkstra(int src, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, vector<int> &dest)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, src});
        dest[src] = 0;

        while (q.size())
        {
            int d = q.top().first;
            int temp = q.top().second;
            q.pop();

            if (visited[temp])
                continue;

            visited[temp] = 1;

            for (int i = 0; i < adj[temp].size(); i++)
            {
                int nbr = adj[temp][i].first;
                int w = adj[temp][i].second;

                if (!visited[nbr] && dest[nbr] > d + w)
                {
                    dest[nbr] = d + w;
                    q.push({dest[nbr], nbr});
                }
            }
        }
    }

    void makeAdj(vector<vector<int>> &edges, vector<vector<pair<int, int>>> &adj)
    {
        int E = edges.size();

        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adj(V);

        makeAdj(edges, adj);

        vector<bool> visited(V, 0);
        vector<int> dest(V, INT_MAX);

        Dijkstra(src, adj, visited, dest);

        return dest;
    }
};

int main()
{
    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}};

    int src = 0;

    Solution obj;

    vector<int> ans = obj.dijkstra(V, edges, src);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Distance from " << src << " to " << i << " = " << ans[i] << endl;
    }

    return 0;
}