#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[lo] == nums[mid] && nums[mid] == nums[hi])
            {
                lo++;
                hi--;
            }

            // Left half is sorted
            else if (nums[lo] <= nums[mid])
            {
                if (nums[lo] <= target && target < nums[mid])
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }

            // Right half is sorted
            else
            {
                if (nums[mid] < target && target <= nums[hi])
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    bool ans = obj.search(nums, target);

    if (ans)
    {
        cout << "Target found" << endl;
    }
    else
    {
        cout << "Target not found" << endl;
    }

    return 0;
}