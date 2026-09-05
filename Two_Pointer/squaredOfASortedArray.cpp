#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);

        int lo = 0;
        int hi = n - 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (abs(nums[lo]) > abs(nums[hi]))
            {
                ans[i] = nums[lo] * nums[lo];
                lo++;
            }
            else
            {
                ans[i] = nums[hi] * nums[hi];
                hi--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> ans = obj.sortedSquares(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}