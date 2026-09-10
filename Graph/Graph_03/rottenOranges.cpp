#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void BFS(vector<vector<int>> &adj, int &time)
    {

        int r = adj.size();
        int c = adj[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                if (adj[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        while (q.size())
        {

            bool rotten = false;
            int n = q.size();

            for (int k = 0; k < n; k++)
            {

                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                // Up
                if (i - 1 >= 0 && adj[i - 1][j] == 1)
                {
                    adj[i - 1][j] = 2;
                    q.push({i - 1, j});
                    rotten = true;
                }

                // Down
                if (i + 1 < r && adj[i + 1][j] == 1)
                {
                    adj[i + 1][j] = 2;
                    q.push({i + 1, j});
                    rotten = true;
                }

                // Left
                if (j - 1 >= 0 && adj[i][j - 1] == 1)
                {
                    adj[i][j - 1] = 2;
                    q.push({i, j - 1});
                    rotten = true;
                }

                // Right
                if (j + 1 < c && adj[i][j + 1] == 1)
                {
                    adj[i][j + 1] = 2;
                    q.push({i, j + 1});
                    rotten = true;
                }
            }

            if (rotten)
            {
                time++;
            }
        }
    }

    int orangesRot(vector<vector<int>> &adj)
    {

        int r = adj.size();
        int c = adj[0].size();

        int time = 0;

        BFS(adj, time);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                if (adj[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};

int main()
{

    vector<vector<int>> adj = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    Solution obj;

    cout << "Time: " << obj.orangesRot(adj) << endl;

    return 0;
}