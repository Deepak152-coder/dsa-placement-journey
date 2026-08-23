#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            st.push(s[i]);
        }

        int i = 0;

        while (!st.empty())
        {
            s[i] = st.top();
            st.pop();
            i++;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<char> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    Solution obj;

    obj.reverseString(s);

    for (char c : s)
    {
        cout << c << " ";
    }

    return 0;
}