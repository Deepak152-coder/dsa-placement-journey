#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {

            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            for (int j = i + 1; j < n; j++)
            {

                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;

                int lo = j + 1;
                int hi = n - 1;

                while (lo < hi)
                {

                    long long val = (long long)arr[i] +
                                    (long long)arr[j] +
                                    (long long)arr[lo] +
                                    (long long)arr[hi];

                    if (val == k)
                    {

                        ans.push_back({arr[i],
                                       arr[j],
                                       arr[lo],
                                       arr[hi]});

                        while (lo < hi && arr[lo] == arr[lo + 1])
                            lo++;

                        while (lo < hi && arr[hi] == arr[hi - 1])
                            hi--;

                        lo++;
                        hi++;
                    }
                    else if (val > k)
                    {
                        hi--;
                    }
                    else
                    {
                        lo++;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int k = 0;

    vector<vector<int>> ans = obj.fourSum(arr, k);

    for (auto v : ans)
    {
        cout << "[";

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];

            if (i != v.size() - 1)
                cout << ", ";
        }

        cout << "]" << endl;
    }

    return 0;
}