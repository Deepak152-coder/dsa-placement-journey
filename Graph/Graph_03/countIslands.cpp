#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(int i, int j, vector<vector<char>> &adj, vector<vector<bool>> &visited)
    {

        visited[i][j] = 1;

        int r = adj.size();
        int c = adj[0].size();

        // Up
        if (i - 1 >= 0 && adj[i - 1][j] == 'L' && visited[i - 1][j] == 0)
        {
            DFS(i - 1, j, adj, visited);
        }

        // Down
        if (i + 1 < r && adj[i + 1][j] == 'L' && visited[i + 1][j] == 0)
        {
            DFS(i + 1, j, adj, visited);
        }

        // Left
        if (j - 1 >= 0 && adj[i][j - 1] == 'L' && visited[i][j - 1] == 0)
        {
            DFS(i, j - 1, adj, visited);
        }

        // Right
        if (j + 1 < c && adj[i][j + 1] == 'L' && visited[i][j + 1] == 0)
        {
            DFS(i, j + 1, adj, visited);
        }

        // Top-Left
        if (i - 1 >= 0 && j - 1 >= 0 &&
            adj[i - 1][j - 1] == 'L' && visited[i - 1][j - 1] == 0)
        {
            DFS(i - 1, j - 1, adj, visited);
        }

        // Top-Right
        if (i - 1 >= 0 && j + 1 < c &&
            adj[i - 1][j + 1] == 'L' && visited[i - 1][j + 1] == 0)
        {
            DFS(i - 1, j + 1, adj, visited);
        }

        // Bottom-Left
        if (i + 1 < r && j - 1 >= 0 &&
            adj[i + 1][j - 1] == 'L' && visited[i + 1][j - 1] == 0)
        {
            DFS(i + 1, j - 1, adj, visited);
        }

        // Bottom-Right
        if (i + 1 < r && j + 1 < c &&
            adj[i + 1][j + 1] == 'L' && visited[i + 1][j + 1] == 0)
        {
            DFS(i + 1, j + 1, adj, visited);
        }
    }

    int countIslands(vector<vector<char>> &adj)
    {

        int r = adj.size();
        int c = adj[0].size();

        vector<vector<bool>> visited(r, vector<bool>(c, 0));

        int count = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                if (adj[i][j] == 'L' && visited[i][j] == 0)
                {
                    DFS(i, j, adj, visited);
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{

    vector<vector<char>> adj = {
        {'L', 'L', 'W', 'W'},
        {'W', 'L', 'W', 'L'},
        {'L', 'W', 'W', 'L'},
        {'W', 'W', 'L', 'L'}};

    Solution obj;

    cout << "Number of Islands: " << obj.countIslands(adj) << endl;

    return 0;
}