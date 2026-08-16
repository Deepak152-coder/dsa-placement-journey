#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextSmaller(vector<int> &arr, stack<int> &st, vector<int> &right)
    {

        for (int i = 0; i < arr.size(); i++)
        {

            while (st.size() && arr[st.top()] > arr[i])
            {
                right[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }
    }

    void prevSmaller(vector<int> &arr, stack<int> &st, vector<int> &left)
    {

        for (int i = arr.size() - 1; i >= 0; i--)
        {

            while (st.size() && arr[st.top()] > arr[i])
            {
                left[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }
    }

    void maxVal(vector<int> &arr,
                vector<int> &left,
                vector<int> &right,
                int &ans)
    {

        for (int i = 0; i < left.size(); i++)
        {
            ans = max(ans,
                      arr[i] * (right[i] - left[i] - 1));
        }
    }

    int maximalRectangle(vector<vector<char>> &mat)
    {

        int n = mat.size();

        if (n == 0)
            return 0;

        int m = mat[0].size();

        vector<int> arr(m, 0);

        int ans = -1;

        for (int i = 0; i < n; i++)
        {

            vector<int> left(m, -1);
            vector<int> right(m, m);

            // Build histogram
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == '1')
                {
                    arr[j]++;
                }
                else
                {
                    arr[j] = 0;
                }
            }

            // Next smaller
            stack<int> st;

            nextSmaller(arr, st, right);

            // Clear stack
            while (st.size())
            {
                st.pop();
            }

            // Previous smaller
            prevSmaller(arr, st, left);

            // Calculate maximum area
            maxVal(arr, left, right, ans);
        }

        return ans;
    }
};

int main()
{

    vector<vector<char>> mat = {
        {'0', '0', '0', '1', '0', '1', '0'},
        {'0', '1', '0', '0', '0', '0', '0'},
        {'0', '1', '0', '1', '0', '0', '1'},
        {'0', '0', '1', '1', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '0'},
        {'1', '0', '0', '1', '0', '1', '1'},
        {'0', '1', '0', '0', '1', '0', '1'},
        {'1', '1', '0', '1', '1', '1', '0'},
        {'1', '0', '1', '0', '1', '0', '1'},
        {'1', '1', '1', '0', '0', '0', '0'}};

    Solution obj;

    cout << "Maximum Rectangle Area: "
         << obj.maximalRectangle(mat)
         << endl;

    return 0;
}