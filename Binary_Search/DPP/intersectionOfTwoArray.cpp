#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<int> &arr, int k)
    {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] == k)
            {
                return true;
            }
            else if (arr[mid] < k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return false;
    }

    vector<int> intersection(vector<int> &arr, vector<int> &brr)
    {
        int n = arr.size();
        int m = brr.size();

        set<int> st;
        vector<int> ans;

        if (m > n)
        {
            return intersection(brr, arr);
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < brr.size(); i++)
        {
            if (exist(arr, brr[i]))
            {
                st.insert(brr[i]);
            }
        }

        for (auto x : st)
        {
            ans.push_back(x);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {4, 9, 5};
    vector<int> brr = {9, 4, 9, 8, 4};

    vector<int> ans = obj.intersection(arr, brr);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}