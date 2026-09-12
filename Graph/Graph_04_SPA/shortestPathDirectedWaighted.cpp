#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(int temp, stack<int> &st, vector<bool> &visited, vector<vector<pair<int, int>>> &adj)
    {
        visited[temp] = 1;

        for (int i = 0; i < adj[temp].size(); i++)
        {
            if (visited[adj[temp][i].first] == 0)
            {
                DFS(adj[temp][i].first, st, visited, adj);
            }
        }

        st.push(temp);
    }

    void getAns(stack<int> &st, vector<int> &dest, vector<vector<pair<int, int>>> &adj)
    {
        while (st.size())
        {
            int temp = st.top();
            st.pop();

            for (int i = 0; i < adj[temp].size(); i++)
            {
                int nbr = adj[temp][i].first;
                int w = adj[temp][i].second;

                dest[nbr] = min(dest[nbr], w + dest[temp]);
            }
        }

        for (int i = 0; i < dest.size(); i++)
        {
            if (dest[i] == INT_MAX)
            {
                dest[i] = -1;
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
        }
    }

    vector<int> shortestPath(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);

        makeAdj(edges, adj);

        stack<int> st;
        vector<bool> visited(V, 0);
        vector<int> dest(V, INT_MAX);

        dest[0] = 0;

        DFS(0, st, visited, adj);

        getAns(st, dest, adj);

        return dest;
    }
};

int main()
{
    int V = 6;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {2, 3, 6},
        {4, 5, 4},
        {5, 3, 1}};

    Solution obj;

    vector<int> ans = obj.shortestPath(V, edges);

    cout << "Shortest distances from source 0:" << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << " -> " << ans[i] << endl;
    }

    return 0;
}