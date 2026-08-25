#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int k, long long mid)
{
    int painter = 1;
    long long wall = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (wall + arr[i] <= mid)
        {
            wall += arr[i];
        }
        else
        {
            painter++;
            wall = arr[i];
        }

        if (painter > k)
        {
            return false;
        }
    }

    return true;
}

long long minTime(vector<int> &arr, int k)
{
    int n = arr.size();

    if (k > n)
    {
        return -1;
    }

    long long lo = 0;
    long long hi = 0;

    for (int i = 0; i < n; i++)
    {
        lo = max(lo, (long long)arr[i]);
        hi += arr[i];
    }

    long long ans = hi;

    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;

        if (isPossible(arr, k, mid))
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

int main()
{
    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;

    cout << minTime(arr, k) << endl;

    return 0;
}