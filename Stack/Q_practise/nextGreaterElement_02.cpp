#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            nums.push_back(nums[i]);
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < 2 * n; i++)
        {
            while (st.size() && nums[st.top()] < nums[i % n])
            {
                if (st.top() < n)
                {
                    ans[st.top()] = nums[i % n];
                }

                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1};

    Solution obj;

    vector<int> ans = obj.nextGreaterElements(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}