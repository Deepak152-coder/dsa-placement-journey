#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int target)
{
    int lo = 0;
    int hi = arr.size() - 1;
    int ans = -1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        int val = arr[mid] - mid - 1;

        if (val >= target)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}

int findKthPositive(vector<int> &arr, int k)
{
    int ans = solve(arr, k);

    if (ans == -1)
    {
        return arr.size() + k;
    }

    return ans + k;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << findKthPositive(arr, k) << endl;

    return 0;
}