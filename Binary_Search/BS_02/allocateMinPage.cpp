#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int k, long long mid)
{
    int students = 1;
    long long pages = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        if (pages + arr[i] <= mid)
        {
            pages += arr[i];
        }
        else
        {
            students++;
            pages = arr[i];
        }

        if (students > k)
        {
            return false;
        }
    }

    return true;
}

int findPages(vector<int> &arr, int k)
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

    return (int)ans;
}

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;

    cout << findPages(arr, k) << endl;

    return 0;
}