#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> makeBeautiful(vector<int> arr)
    {
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            if (!st.empty() &&
                ((arr[i] < 0 && st.top() >= 0) ||
                 (arr[i] >= 0 && st.top() < 0)))
            {
                st.pop();
            }
            else
            {
                st.push(arr[i]);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

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

    vector<int> ans = obj.makeBeautiful(arr);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}