#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums, int k, long long maxSum)
{
    int subarrays = 1;
    long long currentSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (currentSum + nums[i] <= maxSum)
        {
            currentSum += nums[i];
        }
        else
        {
            subarrays++;
            currentSum = nums[i];
        }

        if (subarrays > k)
        {
            return false;
        }
    }

    return true;
}

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();

    long long low = 0;
    long long high = 0;

    for (int i = 0; i < n; i++)
    {
        low = max(low, (long long)nums[i]);
        high += nums[i];
    }

    long long answer = high;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (isPossible(nums, k, mid))
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return (int)answer;
}

int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << splitArray(nums, k) << endl;

    return 0;
}