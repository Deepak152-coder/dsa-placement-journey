#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int i, int j, int n)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    void BFS(vector<int> &src, vector<int> &dest, int n,
             vector<vector<bool>> &visited, int &count)
    {

        int i = src[0] - 1;
        int j = src[1] - 1;

        int x = dest[0] - 1;
        int y = dest[1] - 1;

        int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        queue<pair<pair<int, int>, int>> q;

        q.push({{i, j}, 0});
        visited[i][j] = 1;

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

            for (int k = 0; k < 8; k++)
            {

                int ni = i + dr[k];
                int nj = j + dc[k];

                if (isValid(ni, nj, n) && visited[ni][nj] == 0)
                {
                    q.push({{ni, nj}, t + 1});
                    visited[ni][nj] = 1;
                }
            }
        }

        count = 1e8;
    }

    int minStepToReachTarget(vector<int> &src, vector<int> &dest, int n)
    {

        vector<vector<bool>> visited(n, vector<bool>(n, 0));

        int count = 0;

        if (src == dest)
        {
            return 0;
        }

        BFS(src, dest, n, visited, count);

        if (count == 1e8)
        {
            return -1;
        }

        return count;
    }
};

int main()
{

    Solution obj;

    int n = 6;

    vector<int> src = {4, 5};
    vector<int> dest = {1, 1};

    cout << obj.minStepToReachTarget(src, dest, n) << endl;

    return 0;
}