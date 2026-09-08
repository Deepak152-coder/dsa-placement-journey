#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(int temp, vector<vector<int>> &adj,
             vector<bool> &visited, stack<int> &st)
    {

        visited[temp] = 1;

        for (int i = 0; i < adj[temp].size(); i++)
        {
            if (visited[adj[temp][i]] == 0)
            {
                DFS(adj[temp][i], adj, visited, st);
            }
        }

        st.push(temp);
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
        }
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);

        makeAdj(edges, adj);

        vector<bool> visited(V, 0);
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                DFS(i, adj, visited, st);
            }
        }

        while (st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};