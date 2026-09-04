#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int lo = 1;
        int hi = nums[n - 1];

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            int a = nums.end() - lower_bound(nums.begin(), nums.end(), mid);

            if (a == mid)
            {
                return mid;
            }
            else if (a < mid)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {3, 5};

    cout << obj.specialArray(nums) << endl;

    return 0;
}