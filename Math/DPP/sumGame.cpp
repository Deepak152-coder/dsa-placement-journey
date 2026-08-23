#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool sumGame(string s)
    {

        int n = s.size();
        int qd = 0;
        int diff = 0;
        int qt = 0;

        for (int i = 0; i < n / 2; i++)
        {

            if (s[i] == '?')
            {
                qd++;
                qt++;
            }
            else
            {
                diff += s[i] - '0';
            }
        }

        for (int i = n / 2; i < n; i++)
        {

            if (s[i] == '?')
            {
                qd--;
                qt++;
            }
            else
            {
                diff -= s[i] - '0';
            }
        }

        if (qt % 2 == 1)
        {
            return true;
        }

        bool ans = diff != -9 * (qd / 2);

        return ans;
    }
};

int main()
{

    string s = "?6?6?000?3";

    Solution obj;

    bool ans = obj.sumGame(s);

    cout << boolalpha << ans << endl;

    return 0;
}