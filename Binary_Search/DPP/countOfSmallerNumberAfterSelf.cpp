#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int>> &arr, int lo, int mid, int hi,
           vector<int> &count)
{

    int i = lo;
    int j = mid + 1;

    vector<pair<int, int>> ans;

    while (i <= mid && j <= hi)
    {

        if (arr[j].first >= arr[i].first)
        {
            ans.push_back(arr[j]);
            j++;
        }
        else
        {
            count[arr[i].second] += hi - j + 1;
            ans.push_back(arr[i]);
            i++;
        }
    }

    while (i <= mid)
    {
        count[arr[i].second] += hi - j + 1;
        ans.push_back(arr[i]);
        i++;
    }

    while (j <= hi)
    {
        ans.push_back(arr[j]);
        j++;
    }

    for (int k = lo; k <= hi; k++)
    {
        arr[k] = ans[k - lo];
    }
}

void mergeSort(vector<pair<int, int>> &arr, int lo, int hi,
               vector<int> &count)
{

    if (lo >= hi)
    {
        return;
    }

    int mid = lo + (hi - lo) / 2;

    mergeSort(arr, lo, mid, count);
    mergeSort(arr, mid + 1, hi, count);

    merge(arr, lo, mid, hi, count);
}

vector<int> countSmaller(vector<int> &nums)
{

    int n = nums.size();

    vector<int> count(n, 0);
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        arr.push_back({nums[i], i});
    }

    mergeSort(arr, 0, n - 1, count);

    return count;
}

int main()
{

    vector<int> nums = {5, 2, 6, 1};

    vector<int> ans = countSmaller(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}