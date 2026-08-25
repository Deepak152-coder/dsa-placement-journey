#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &weights, int days, long long capacity)
{
    int currentDays = 1;
    long long currentWeight = 0;

    for (int i = 0; i < weights.size(); i++)
    {

        if (currentWeight + weights[i] <= capacity)
        {
            currentWeight += weights[i];
        }
        else
        {
            currentDays++;
            currentWeight = weights[i];
        }

        if (currentDays > days)
        {
            return false;
        }
    }

    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{

    int n = weights.size();

    if (days > n)
    {
        return -1;
    }

    long long low = 0;
    long long high = 0;

    for (int i = 0; i < n; i++)
    {
        low = max(low, (long long)weights[i]);
        high += weights[i];
    }

    long long answer = high;

    while (low <= high)
    {

        long long mid = low + (high - low) / 2;

        if (isPossible(weights, days, mid))
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
    vector<int> weights = {1, 2, 3, 1, 1};
    int days = 4;

    cout << shipWithinDays(weights, days) << endl;

    return 0;
}