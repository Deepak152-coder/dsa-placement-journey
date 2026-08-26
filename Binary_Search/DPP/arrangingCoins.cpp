#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int lo = 0;
        int hi = n;
        int ans = 0;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            long long val = ((long long)mid * (mid + 1)) / 2;

            if (val <= n)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n;
    cin >> n;

    cout << obj.arrangeCoins(n) << endl;

    return 0;
}