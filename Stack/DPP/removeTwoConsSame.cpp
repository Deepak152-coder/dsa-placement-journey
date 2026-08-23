#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeConsecutiveSame(vector<string> &arr)
    {
        stack<string> st;

        for (int i = 0; i < arr.size(); i++)
        {
            if (!st.empty() && st.top() == arr[i])
            {
                st.pop();
            }
            else
            {
                st.push(arr[i]);
            }
        }

        int count = 0;

        while (!st.empty())
        {
            st.pop();
            count++;
        }

        return count;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.removeConsecutiveSame(arr);

    return 0;
}