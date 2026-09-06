#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int ans = 0;

        // Push all initially rotten oranges
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        // BFS
        while (!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;

            q.pop();

            ans = max(ans, t);

            // Up
            if (i - 1 >= 0 &&
                visited[i - 1][j] == 0 &&
                grid[i - 1][j] == 1)
            {

                q.push({{i - 1, j}, t + 1});
                visited[i - 1][j] = 1;
            }

            // Down
            if (i + 1 < n &&
                visited[i + 1][j] == 0 &&
                grid[i + 1][j] == 1)
            {

                q.push({{i + 1, j}, t + 1});
                visited[i + 1][j] = 1;
            }

            // Left
            if (j - 1 >= 0 &&
                visited[i][j - 1] == 0 &&
                grid[i][j - 1] == 1)
            {

                q.push({{i, j - 1}, t + 1});
                visited[i][j - 1] = 1;
            }

            // Right
            if (j + 1 < m &&
                visited[i][j + 1] == 0 &&
                grid[i][j + 1] == 1)
            {

                q.push({{i, j + 1}, t + 1});
                visited[i][j + 1] = 1;
            }
        }

        // Check if any fresh orange is still left
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};