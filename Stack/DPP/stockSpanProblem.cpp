#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, 1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && arr[st.top()] < arr[i])
            {
                ans[st.top()] = st.top() - i;
                st.pop();
            }

            st.push(i);
        }

        while (st.size())
        {
            ans[st.top()] = st.top() + 1;
            st.pop();
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    vector<int> ans = obj.calculateSpan(arr);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}