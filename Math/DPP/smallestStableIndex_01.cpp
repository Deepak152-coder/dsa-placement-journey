#include <bits/stdc++.h>
using namespace std;

int firstStableIndex(vector<int> &arr, int k)
{
    int ans = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        int a = *max_element(arr.begin(), arr.begin() + i + 1);
        int b = *min_element(arr.begin() + i, arr.end());

        int c = a - b;

        if (c <= k)
        {
            ans = i;
            return i;
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

    cout << firstStableIndex(arr, k) << endl;

    return 0;
}