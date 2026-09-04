#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();

        int a = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        int b = nums.end() - upper_bound(nums.begin(), nums.end(), 0);

        return max(a, b);
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};

    cout << obj.maximumCount(nums) << endl;

    return 0;
}