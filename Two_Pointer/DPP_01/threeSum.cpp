#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> arr;

        for (int i = 0; i < nums.size(); i++)
        {
            int lo = i + 1;
            int hi = nums.size() - 1;

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            while (lo < hi)
            {
                if (nums[i] + nums[lo] + nums[hi] == 0)
                {
                    arr.push_back({nums[i], nums[lo], nums[hi]});

                    while (lo < hi && nums[lo] == nums[lo + 1])
                        lo++;

                    while (lo < hi && nums[hi] == nums[hi - 1])
                        hi--;

                    lo++;
                    hi--;
                }
                else if (nums[i] + nums[lo] + nums[hi] > 0)
                {
                    hi--;
                }
                else
                {
                    lo++;
                }
            }
        }

        return arr;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = obj.threeSum(nums);

    for (auto &v : ans)
    {
        cout << "[";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i + 1 < v.size())
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}