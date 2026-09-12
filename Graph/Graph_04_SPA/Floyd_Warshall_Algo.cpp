#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Floyd_Warshall_Algo(vector<vector<int>> &mat)
    {
        int n = mat.size();

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][k] == 1e8 || mat[k][j] == 1e8)
                        continue;

                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    void floydWarshall(vector<vector<int>> &mat)
    {
        Floyd_Warshall_Algo(mat);
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> mat = {
        {0, 5, 1e8, 10},
        {1e8, 0, 3, 1e8},
        {1e8, 1e8, 0, 1},
        {1e8, 1e8, 1e8, 0}};

    obj.floydWarshall(mat);

    for (auto &row : mat)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}