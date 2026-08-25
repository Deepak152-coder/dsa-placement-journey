#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        // Left side Sorted
        else if (nums[mid] >= nums[0])
        {
            if (nums[mid] >= target && nums[0] <= target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        // Right side Sorted
        else
        {
            if (nums[mid] <= target && nums[hi] >= target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << search(nums, target) << endl;

    return 0;
}