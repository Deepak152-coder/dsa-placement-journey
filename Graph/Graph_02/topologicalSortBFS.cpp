#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void BFS(vector<int> &InDegree, vector<int> &ans,
             vector<vector<int>> &adj)
    {

        int V = InDegree.size();
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (InDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (q.size())
        {
            int temp = q.front();
            q.pop();

            ans.push_back(temp);

            for (int i = 0; i < adj[temp].size(); i++)
            {
                InDegree[adj[temp][i]]--;

                if (InDegree[adj[temp][i]] == 0)
                {
                    q.push(adj[temp][i]);
                }
            }
        }
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

        vector<int> InDegree(V, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                InDegree[adj[i][j]]++;
            }
        }

        BFS(InDegree, ans, adj);

        return ans;
    }
};