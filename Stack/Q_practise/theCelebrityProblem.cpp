#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {

        stack<int> st;
        int n = mat.size();

        // Push all people into stack
        for (int i = n - 1; i >= 0; i--)
        {
            st.push(i);
        }

        // Find possible celebrity
        while (st.size() > 1)
        {

            int first = st.top();
            st.pop();

            int second = st.top();
            st.pop();

            if (mat[first][second] == 1)
            {
                // first knows second
                // first cannot be celebrity
                st.push(second);
            }
            else
            {
                // first does not know second
                // second cannot be celebrity
                st.push(first);
            }
        }

        if (!st.size())
        {
            return -1;
        }

        int val = st.top();
        st.pop();

        int rsum = 0;
        int csum = 0;

        // Verify candidate
        for (int i = 0; i < n; i++)
        {

            if (i == val)
                continue;

            rsum += mat[val][i];
            csum += mat[i][val];
        }

        // Celebrity knows nobody
        // Everybody knows celebrity
        if (rsum == 0 && csum == n - 1)
        {
            return val;
        }

        return -1;
    }
};

int main()
{

    vector<vector<int>> mat = {
        {1, 1, 0},
        {0, 1, 0},
        {1, 1, 1}};

    Solution obj;

    cout << "Celebrity: " << obj.celebrity(mat) << endl;

    return 0;
}