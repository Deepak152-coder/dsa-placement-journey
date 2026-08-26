#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int lo = 0;
        int hi = num;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            long long val = (long long)mid * mid;

            if (val == num)
            {
                return true;
            }
            else if (val > num)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;

    int num;
    cin >> num;

    cout << boolalpha << obj.isPerfectSquare(num) << endl;

    return 0;
}