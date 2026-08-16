#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> prevSmaller(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && arr[st.top()] > arr[i])
            {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 5, 0, 3, 4, 5};

    Solution obj;

    vector<int> ans = obj.prevSmaller(arr);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}