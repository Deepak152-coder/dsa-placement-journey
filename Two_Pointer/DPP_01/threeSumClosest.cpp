#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &arr, int k)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int ans = arr[0] + arr[1] + arr[2];

        for (int i = 0; i < n - 2; i++)
        {
            int lo = i + 1;
            int hi = n - 1;

            while (lo < hi)
            {
                int val = arr[i] + arr[lo] + arr[hi];

                if (val == k)
                {
                    return val;
                }

                if (abs(val - k) < abs(ans - k))
                {
                    ans = val;
                }

                if (val > k)
                {
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
    Solution obj;

    vector<int> arr = {-1, 2, 1, -4};
    int k = 1;

    cout << obj.threeSumClosest(arr, k) << endl;

    return 0;
}