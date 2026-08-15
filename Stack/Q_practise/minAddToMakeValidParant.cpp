#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {

            if (!st.empty() &&
                ((s[i] == ')' && st.top() == '(') ||
                 (s[i] == '}' && st.top() == '{') ||
                 (s[i] == ']' && st.top() == '[')))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
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
    string s;
    cin >> s;

    Solution obj;

    cout << obj.minAddToMakeValid(s);

    return 0;
}