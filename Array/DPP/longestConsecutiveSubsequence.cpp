#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        for (auto x : st)
        {
            if (st.find(x - 1) == st.end())
            {

                int count = 1;
                int curr = x;

                while (st.find(curr + 1) != st.end())
                {
                    curr++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << sol.longestConsecutive(nums) << endl;

    return 0;
}