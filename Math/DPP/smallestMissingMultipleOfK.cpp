#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        vector<bool> flag(nums.size() + 1, false);

        flag[0] = true;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % k == 0)
            {
                int q = nums[i] / k;

                if (q <= nums.size())
                {
                    flag[q] = true;
                }
            }
        }

        for (int i = 0; i <= nums.size(); i++)
        {
            if (flag[i] == false)
            {
                return i * k;
            }
        }

        return (nums.size() + 1) * k;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {99};
    int k = 99;

    cout << obj.missingMultiple(nums, k) << endl;

    return 0;
}