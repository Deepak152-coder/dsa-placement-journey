#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int lo = 1;
        int hi = arr.size() - 2;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {0, 2, 5, 7, 6, 3, 1};

    cout << "Peak Index: " << obj.peakIndexInMountainArray(arr) << endl;

    return 0;
}