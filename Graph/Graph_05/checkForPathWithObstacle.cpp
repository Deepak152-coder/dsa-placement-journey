#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void BFS(vector<vector<int>> &mat, int i, int j, int x, int y, int &count)
    {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;

        q.push({{i, j}, 0});
        mat[i][j] = 0;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        while (q.size())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            if (i == x && j == y)
            {
                count = t;
                return;
            }

            for (int k = 0; k < 4; k++)
            {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if (isValid(ni, nj, n, m) &&
                    (mat[ni][nj] == 3 || mat[ni][nj] == 2))
                {
                    q.push({{ni, nj}, t + 1});
                    mat[ni][nj] = 0;
                }
            }
        }

        count = 1e8;
    }

    bool isPathPossible(vector<vector<int>> &mat)
    {
        int count = 0;
        int n = mat.size();
        int m = mat[0].size();

        int i, j, x, y;

        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < m; b++)
            {
                if (mat[a][b] == 1)
                {
                    i = a;
                    j = b;
                }
                else if (mat[a][b] == 2)
                {
                    x = a;
                    y = b;
                }
            }
        }

        if (i == x && j == y)
        {
            return true;
        }

        BFS(mat, i, j, x, y, count);

        if (count == 1e8)
        {
            return false;
        }

        return true;
    }
};

// TC: O(N * M)
// SC: O(N * M)

int main()
{
    Solution obj;

    vector<vector<int>> mat = {
        {1, 3, 0, 0},
        {0, 3, 3, 0},
        {0, 0, 3, 2},
        {0, 0, 0, 0}};

    cout << obj.isPathPossible(mat) << endl;

    return 0;
}