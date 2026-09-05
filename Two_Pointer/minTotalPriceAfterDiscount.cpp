#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double minPrice(vector<int> &arr, vector<int> &brr)
    {
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        int n = arr.size();
        double ans = 0.0;
        int j = brr.size() - 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (j >= 0)
            {
                ans += (double)arr[i] * (100 - (double)brr[j]) / 100;
                j--;
            }
            else
            {
                ans += (double)arr[i];
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {10, 30, 21};
    vector<int> brr = {50, 60};

    cout << fixed << setprecision(5);
    cout << obj.minPrice(arr, brr) << endl;

    return 0;
}