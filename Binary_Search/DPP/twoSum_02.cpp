#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int tar)
    {

        for (int i = 0; i < arr.size(); i++)
        {

            int need = tar - arr[i];

            int lo = i + 1;
            int hi = arr.size() - 1;

            while (lo <= hi)
            {

                int mid = lo + (hi - lo) / 2;

                if (arr[mid] == need)
                {
                    return {i + 1, mid + 1};
                }
                else if (arr[mid] < need)
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }

        return {-1, -1};
    }
};

int main()
{

    vector<int> arr = {2, 7, 11, 15};
    int tar = 9;

    Solution obj;

    vector<int> ans = obj.twoSum(arr, tar);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}