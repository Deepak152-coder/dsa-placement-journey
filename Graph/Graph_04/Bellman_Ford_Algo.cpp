#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Bellman_Ford_Algo(int V, vector<vector<int>> &edges,
                           vector<int> &dest)
    {

        int E = edges.size();

        // Relax edges V-1 times
        for (int i = 0; i < V - 1; i++)
        {

            for (int j = 0; j < E; j++)
            {

                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];

                if (dest[u] != 1e8 &&
                    dest[u] + w < dest[v])
                {

                    dest[v] = dest[u] + w;
                }
            }
        }

        // Negative Cycle Check
        for (int j = 0; j < E; j++)
        {

            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dest[u] != 1e8 &&
                dest[u] + w < dest[v])
            {

                dest[0] = INT_MIN;
                return;
            }
        }
    }

    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {

        vector<int> dest(V, 1e8);

        dest[src] = 0;

        Bellman_Ford_Algo(V, edges, dest);

        if (dest[0] == INT_MIN)
        {
            return {-1};
        }

        return dest;
    }
};

int main()
{

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (u v w):\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;

    cout << "Enter source: ";
    cin >> src;

    Solution obj;

    vector<int> ans = obj.bellmanFord(V, edges, src);

    cout << "Shortest distances:\n";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}