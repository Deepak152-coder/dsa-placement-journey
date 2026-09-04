#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums1.size(); i++)
    {
        mp[nums1[i]]++;
    }

    vector<int> ans;

    for (auto x : nums2)
    {
        if (mp[x] > 0)
        {
            ans.push_back(x);
            mp[x]--;
        }
    }

    return ans;
}

int main()
{
    int n, m;

    cin >> n;
    vector<int> nums1(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }

    cin >> m;
    vector<int> nums2(m);

    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }

    vector<int> ans = intersect(nums1, nums2);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}