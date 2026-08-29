#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi])
            {
                lo = mid + 1;
            }
            else if (nums[mid] < nums[hi])
            {
                hi = mid;
            }
            else
            {
                hi--;
            }
        }

        return nums[lo];
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {2, 2, 2, 0, 1};

    cout << "Minimum element: " << obj.findMin(nums) << endl;

    return 0;
}