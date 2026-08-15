#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bracketNumbers(string &s)
    {
        int count = 0;
        stack<int> st;
        vector<int> v;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                count++;
                st.push(count);
                v.push_back(st.top());
            }
            else if (s[i] == ')')
            {
                v.push_back(st.top());
                st.pop();
            }
        }

        return v;
    }
};

int main()
{
    string s;
    getline(cin, s);

    Solution obj;
    vector<int> ans = obj.bracketNumbers(s);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}