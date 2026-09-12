#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Dijikstra(int dst, vector<vector<pair<int, int>>> &adj,
                   vector<int> &dest, vector<bool> &visited,
                   vector<int> &parent)
    {

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;

        q.push({0, dst});
        dest[dst] = 0;

        while (q.size())
        {
            int d = q.top().first;
            int temp = q.top().second;
            q.pop();

            if (visited[temp] == 1)
            {
                continue;
            }

            visited[temp] = 1;

            for (int i = 0; i < adj[temp].size(); i++)
            {
                int nbr = adj[temp][i].first;
                int w = adj[temp][i].second;

                if (dest[nbr] > d + w)
                {
                    dest[nbr] = d + w;
                    q.push({dest[nbr], nbr});
                    parent[nbr] = temp;
                }
            }
        }
    }

    void makeAdj(vector<vector<int>> &edges,
                 vector<vector<pair<int, int>>> &adj)
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

    vector<int> shortestPath(int V, vector<vector<int>> &edges,
                             int src, int dst)
    {

        vector<vector<pair<int, int>>> adj(V + 1);

        makeAdj(edges, adj);

        vector<int> dest(V + 1, INT_MAX);
        vector<bool> visited(V + 1, 0);
        vector<int> parent(V + 1, -1);

        Dijikstra(dst, adj, dest, visited, parent);

        vector<int> ans;

        if (dest[src] == INT_MAX)
        {
            return {-1};
        }

        int node = src;
        ans.push_back(node);

        while (node != dst)
        {
            int next = -1;

            for (int i = 0; i < adj[node].size(); i++)
            {
                int nbr = adj[node][i].first;
                int w = adj[node][i].second;

                if (dest[node] == dest[nbr] + w)
                {
                    if (next == -1 || nbr < next)
                    {
                        next = nbr;
                    }
                }
            }

            node = next;
            ans.push_back(node);
        }

        return ans;
    }
};

int main()
{

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src, dst;
    cin >> src >> dst;

    Solution obj;

    vector<int> ans = obj.shortestPath(V, edges, src, dst);

    cout << "[";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];

        if (i != ans.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << "]\n";

    return 0;
}