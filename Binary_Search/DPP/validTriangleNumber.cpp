#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int ans = 0;
        int n = arr.size();

        for (int i = n - 1; i >= 2; i--)
        {
            int lo = 0;
            int hi = i - 1;

            while (lo < hi)
            {
                if (arr[lo] + arr[hi] > arr[i])
                {
                    ans += hi - lo;
                    hi--;
                }
                else
                {
                    lo++;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {2, 2, 3, 4};

    cout << sol.triangleNumber(arr) << endl;

    return 0;
}