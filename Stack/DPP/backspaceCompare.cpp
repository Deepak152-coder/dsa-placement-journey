#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st;
        stack<char> vt;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
            {
                if (!vt.empty())
                {
                    vt.pop();
                }
            }
            else
            {
                vt.push(t[i]);
            }
        }

        return st == vt;
    }
};

int main()
{
    string s, t;

    cin >> s >> t;

    Solution obj;

    if (obj.backspaceCompare(s, t))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}