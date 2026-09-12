#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void BFS(vector<int> &src, vector<int> &dest, vector<vector<int>> &mat, int &count)
    {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;

        int i = src[0];
        int j = src[1];

        q.push({{i, j}, 0});
        mat[i][j] = 0;

        int x = dest[0];
        int y = dest[1];

        while (q.size())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            // up down left right
            if (i == x && j == y)
            {
                count = t;
                return;
            }

            if (i - 1 >= 0 && mat[i - 1][j] == 1)
            {
                q.push({{i - 1, j}, t + 1});
                mat[i - 1][j] = 0;
            }

            if (i + 1 < n && mat[i + 1][j] == 1)
            {
                q.push({{i + 1, j}, t + 1});
                mat[i + 1][j] = 0;
            }

            if (j - 1 >= 0 && mat[i][j - 1] == 1)
            {
                q.push({{i, j - 1}, t + 1});
                mat[i][j - 1] = 0;
            }

            if (j + 1 < m && mat[i][j + 1] == 1)
            {
                q.push({{i, j + 1}, t + 1});
                mat[i][j + 1] = 0;
            }
        }

        count = 1e8;
    }

    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest)
    {

        int n = mat.size();
        int m = mat[0].size();
        int count = 0;

        if (mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0)
        {
            return -1;
        }

        BFS(src, dest, mat, count);

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

    vector<vector<int>> mat = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}};

    vector<int> src = {0, 0};
    vector<int> dest = {3, 3};

    cout << obj.shortestPath(mat, src, dest) << endl;

    return 0;
}