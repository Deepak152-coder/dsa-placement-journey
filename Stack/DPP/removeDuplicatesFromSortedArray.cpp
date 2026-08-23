#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        stack<int> st;

        st.push(nums[0]);

        vector<int> arr;
        int count = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            int temp = st.top();

            if (nums[i] == temp)
            {
                continue;
            }
            else
            {
                st.push(nums[i]);
                count++;
            }
        }

        while (!st.empty())
        {
            arr.push_back(st.top());
            st.pop();
        }

        reverse(arr.begin(), arr.end());

        nums.clear();
        nums = arr;

        return count;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "Count: " << k << endl;

    cout << "Array: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}