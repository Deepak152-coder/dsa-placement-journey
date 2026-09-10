#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool BFS(int start, vector<vector<int>> &adj, vector<int> &colour)
    {
        queue<int> q;

        q.push(start);
        colour[start] = 0;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (int i = 0; i < adj[temp].size(); i++)
            {

                if (colour[adj[temp][i]] == -1)
                {
                    colour[adj[temp][i]] = (colour[temp] + 1) % 2;
                    q.push(adj[temp][i]);
                }
                else
                {
                    if (colour[temp] == colour[adj[temp][i]])
                    {
                        return 0;
                    }
                }
            }
        }

        return 1;
    }

    bool isBipartite(vector<vector<int>> &adj)
    {
        int V = adj.size();

        vector<int> colour(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (colour[i] == -1)
            {
                if (!BFS(i, adj, colour))
                {
                    return 0;
                }
            }
        }

        return 1;
    }
};

int main()
{

    vector<vector<int>> adj = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}};

    Solution obj;

    if (obj.isBipartite(adj))
    {
        cout << "Bipartite";
    }
    else
    {
        cout << "Not Bipartite";
    }

    return 0;
}