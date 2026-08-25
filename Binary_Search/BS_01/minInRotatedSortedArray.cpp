#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = nums[0];

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            // Left side sorted
            if (nums[mid] >= nums[0])
            {
                lo = mid + 1;
            }
            // Right side sorted
            else
            {
                ans = nums[mid];
                hi = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << "Minimum element: "
         << obj.findMin(nums) << endl;

    return 0;
}