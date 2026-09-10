#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool DFS(int temp, vector<vector<int>> &adj, vector<int> &colour)
    {

        for (int i = 0; i < adj[temp].size(); i++)
        {

            if (colour[adj[temp][i]] == -1)
            {

                colour[adj[temp][i]] = (colour[temp] + 1) % 2;

                if (!DFS(adj[temp][i], adj, colour))
                {
                    return 0;
                }
            }
            else
            {

                if (colour[temp] == colour[adj[temp][i]])
                {
                    return 0;
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

                colour[i] = 0;

                if (!DFS(i, adj, colour))
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

    Solution obj;

    vector<vector<int>> adj = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}};

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