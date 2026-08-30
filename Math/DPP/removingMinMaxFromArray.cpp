#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int minidx = -1;
        int maxidx = -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxi)
            {
                maxi = nums[i];
                maxidx = i + 1;
            }

            if (nums[i] < mini)
            {
                mini = nums[i];
                minidx = i + 1;
            }
        }

        int n = nums.size();

        int minl = minidx;
        int minr = n - minidx + 1;

        int maxl = maxidx;
        int maxr = n - maxidx + 1;

        int a = max(minl, maxl);
        int b = minl + maxr;
        int c = minr + maxl;
        int d = max(minr, maxr);

        return min({a, b, c, d});
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};

    cout << sol.minimumDeletions(nums) << endl;

    return 0;
}