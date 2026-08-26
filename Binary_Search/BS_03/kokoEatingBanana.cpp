#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int k, long long mid)
{
    long long hours = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        hours += ((long long)arr[i] + mid - 1) / mid;
    }

    return hours <= k;
}

int minEatingSpeed(vector<int> &arr, int k)
{
    int n = arr.size();

    long long lo = 0;
    long long hi = 0;

    for (int i = 0; i < n; i++)
    {
        lo += arr[i];                    // sum
        hi = max(hi, (long long)arr[i]); // maximum element
    }

    lo = lo / k;

    if (lo == 0)
    {
        lo = 1;
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

    return (int)ans;
}

int main()
{
    int n, k;

    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << minEatingSpeed(arr, k) << endl;

    return 0;
}