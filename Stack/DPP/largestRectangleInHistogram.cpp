#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextSmaller(vector<int> &arr, vector<int> &right, stack<int> &st)
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

    void prevSmaller(vector<int> &arr, vector<int> &left, stack<int> &st)
    {
        int n = arr.size();

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && arr[st.top()] > arr[i])
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> left(n, -1);
        vector<int> right(n, n);

        stack<int> st;

        nextSmaller(arr, right, st);

        // Use a fresh stack
        stack<int> st2;
        prevSmaller(arr, left, st2);

        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            int width = right[i] - left[i] - 1;
            int area = arr[i] * width;

            ans = max(ans, area);
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

    cout << obj.largestRectangleArea(arr) << endl;

    return 0;
}