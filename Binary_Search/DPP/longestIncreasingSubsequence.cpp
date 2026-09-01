#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[idx] = nums[i];
            }
        }

        return ans.size();
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << sol.lengthOfLIS(nums) << endl;

    return 0;
}