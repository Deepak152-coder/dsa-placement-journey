#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool DetectCycle(vector<int> &InDeg,
                     vector<int> &ans,
                     vector<vector<int>> &adj)
    {

        queue<int> q;
        int V = adj.size();

        // Push all vertices having indegree 0
        for (int i = 0; i < V; i++)
        {
            if (InDeg[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {

            int temp = q.front();
            q.pop();

            ans.push_back(temp);

            // Remove outgoing edges
            for (int j = 0; j < adj[temp].size(); j++)
            {

                InDeg[adj[temp][j]]--;

                if (InDeg[adj[temp][j]] == 0)
                {
                    q.push(adj[temp][j]);
                }
            }
        }

        // If not all vertices were processed,
        // then a cycle exists
        return ans.size() != V;
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

    bool isCyclic(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);

        makeAdj(edges, adj);

        vector<int> ans;

        vector<int> InDeg(V, 0);

        // Calculate indegree
        for (int i = 0; i < V; i++)
        {

            for (int j = 0; j < adj[i].size(); j++)
            {
                InDeg[adj[i][j]]++;
            }
        }

        if (DetectCycle(InDeg, ans, adj))
        {
            return 1;
        }

        return 0;
    }
};

int main()
{

    Solution obj;

    // Example:
    // 0 -> 1
    // 1 -> 2
    // 2 -> 0
    // This contains a cycle.

    int V = 3;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}};

    if (obj.isCyclic(V, edges))
    {
        cout << "Cycle exists";
    }
    else
    {
        cout << "No cycle";
    }

    return 0;
}