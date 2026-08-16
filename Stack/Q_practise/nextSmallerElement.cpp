#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextSmallerEle(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
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
    vector<int> arr = {4, 8, 5, 2, 25};

    Solution obj;

    vector<int> ans = obj.nextSmallerEle(arr);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}