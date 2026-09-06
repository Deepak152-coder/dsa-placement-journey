#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(vector<int> &arr, int k, int d)
    {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int val = abs(arr[mid] - k);

            if (val <= d)
            {
                return false;
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

        return true;
    }

    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int count = 0;

        sort(arr2.begin(), arr2.end());

        for (int i = 0; i < arr1.size(); i++)
        {
            if (isValid(arr2, arr1[i], d))
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;

    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    cout << obj.findTheDistanceValue(arr1, arr2, d);

    return 0;
}