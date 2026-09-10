#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool DetectCycle(int temp,
                     vector<vector<int>> &adj,
                     vector<bool> &path,
                     vector<bool> &visited)
    {

        path[temp] = 1;
        visited[temp] = 1;

        for (int i = 0; i < adj[temp].size(); i++)
        {

            int neighbour = adj[temp][i];

            // Node is already in current recursion path
            if (path[neighbour] == 1)
            {
                return 1;
            }

            // Node was already completely processed
            if (visited[neighbour] == 1)
            {
                continue;
            }

            if (DetectCycle(neighbour, adj, path, visited))
            {
                return 1;
            }
        }

        // Remove from current recursion path
        path[temp] = 0;

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
        }
    }

    bool isCyclic(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);

        makeAdj(edges, adj);

        vector<bool> path(V, 0);
        vector<bool> visited(V, 0);

        for (int i = 0; i < V; i++)
        {

            if (visited[i] == 0)
            {

                if (DetectCycle(i, adj, path, visited))
                {
                    return 1;
                }
            }
        }

        return 0;
    }
};

int main()
{

    Solution obj;

    // Graph:
    // 0 -> 1
    // 1 -> 2
    // 2 -> 0
    //
    // Cycle: 0 -> 1 -> 2 -> 0

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