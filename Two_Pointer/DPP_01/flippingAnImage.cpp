#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        int n = image.size();

        for (int i = 0; i < n; i++)
        {
            int m = image[i].size();

            reverse(image[i].begin(), image[i].end());

            for (int j = 0; j < m; j++)
            {
                if (image[i][j] == 0)
                {
                    image[i][j] = 1;
                }
                else
                {
                    image[i][j] = 0;
                }
            }
        }

        return image;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> image = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};

    vector<vector<int>> ans = obj.flipAndInvertImage(image);

    for (auto row : ans)
    {
        for (auto x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}