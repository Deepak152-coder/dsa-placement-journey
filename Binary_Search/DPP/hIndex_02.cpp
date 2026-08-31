#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &arr)
    {
        int lo = 0;
        int hi = arr.size() - 1;
        int ans = 0;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            int idxL = arr.size() - mid;

            if (arr[mid] >= idxL)
            {
                ans = idxL;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {0, 1, 3, 5, 6};

    cout << obj.hIndex(arr) << endl;

    return 0;
}