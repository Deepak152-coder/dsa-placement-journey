#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void getval(int n, int &val)
    {

        string s = to_string(n);

        int sum = 0;
        int prod = 1;

        for (int i = 0; i < s.size(); i++)
        {

            int a = s[i] - '0';

            sum += a;
            prod *= a;
        }

        val = sum + prod;
    }

    bool checkDivisibility(int n)
    {

        int val = 0;

        getval(n, val);

        return n % val == 0;
    }
};

int main()
{

    int n = 99;

    Solution obj;

    bool ans = obj.checkDivisibility(n);

    cout << boolalpha << ans << endl;

    return 0;
}