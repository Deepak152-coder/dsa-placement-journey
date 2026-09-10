#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<char>> &adj)
{
    int r = adj.size();
    int c = adj[0].size();

    queue<pair<int, int>> q;

    // First row
    for (int i = 0; i < c; i++)
    {
        if (adj[0][i] == 'O')
        {
            q.push({0, i});
            adj[0][i] = 'T';
        }
    }

    // Last row
    for (int i = 0; i < c; i++)
    {
        if (adj[r - 1][i] == 'O')
        {
            q.push({r - 1, i});
            adj[r - 1][i] = 'T';
        }
    }

    // First column
    for (int i = 0; i < r; i++)
    {
        if (adj[i][0] == 'O')
        {
            q.push({i, 0});
            adj[i][0] = 'T';
        }
    }

    // Last column
    for (int i = 0; i < r; i++)
    {
        if (adj[i][c - 1] == 'O')
        {
            q.push({i, c - 1});
            adj[i][c - 1] = 'T';
        }
    }

    // BFS
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        // Up
        if (i - 1 >= 0 && adj[i - 1][j] == 'O')
        {
            q.push({i - 1, j});
            adj[i - 1][j] = 'T';
        }

        // Down
        if (i + 1 < r && adj[i + 1][j] == 'O')
        {
            q.push({i + 1, j});
            adj[i + 1][j] = 'T';
        }

        // Left
        if (j - 1 >= 0 && adj[i][j - 1] == 'O')
        {
            q.push({i, j - 1});
            adj[i][j - 1] = 'T';
        }

        // Right
        if (j + 1 < c && adj[i][j + 1] == 'O')
        {
            q.push({i, j + 1});
            adj[i][j + 1] = 'T';
        }
    }
}

void fill(vector<vector<char>> &adj)
{
    int r = adj.size();
    int c = adj[0].size();

    BFS(adj);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {

            if (adj[i][j] == 'T')
            {
                adj[i][j] = 'O';
            }
            else if (adj[i][j] == 'O')
            {
                adj[i][j] = 'X';
            }
        }
    }
}

int main()
{

    vector<vector<char>> adj = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    fill(adj);

    // Print result
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[0].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}