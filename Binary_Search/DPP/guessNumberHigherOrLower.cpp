#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pick;

    int guess(int num)
    {
        if (num == pick)
        {
            return 0;
        }
        else if (num < pick)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    int guessNumber(int n)
    {
        int lo = 0;
        int hi = n;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            int val = guess(mid);

            if (val == 0)
            {
                return mid;
            }
            else if (val == 1)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    int n, pick;
    cin >> n >> pick;

    obj.pick = pick;

    cout << obj.guessNumber(n) << endl;

    return 0;
}