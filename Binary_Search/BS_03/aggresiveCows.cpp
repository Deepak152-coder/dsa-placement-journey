#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int k, int mid)
{
    int count = 1;
    int pos = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (pos + mid <= arr[i])
        {
            count++;
            pos = arr[i];
        }
    }

    return count >= k;
}

int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int lo = 1;
    int hi = arr[n - 1] - arr[0];

    int ans = 0;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (isPossible(arr, k, mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ans;
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

    cout << aggressiveCows(arr, k) << endl;

    return 0;
}