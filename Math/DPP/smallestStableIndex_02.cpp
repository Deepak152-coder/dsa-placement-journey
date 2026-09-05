#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> maxi(n, 0);
        vector<int> mini(n, 0);

        int ans = INT_MIN;
        int mans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, nums[i]);
            maxi[i] = ans;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            mans = min(mans, nums[i]);
            mini[i] = mans;
        }

        for (int i = 0; i < n; i++)
        {
            if (maxi[i] - mini[i] <= k)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {10, 5, 7, 3, 6};
    int k = 5;

    cout << obj.firstStableIndex(nums, k) << endl;

    return 0;
}