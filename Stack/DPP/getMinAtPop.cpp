#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[], int n)
{
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push(arr[i]);
    }

    return st;
}

void miniVal(stack<int> st, int &mini)
{
    while (!st.empty())
    {
        mini = min(mini, st.top());
        st.pop();
    }
}

void getMin(stack<int> &st, vector<int> &arr)
{
    while (!st.empty())
    {
        int mini = st.top();

        miniVal(st, mini);

        arr.push_back(mini);

        st.pop();
    }
}

// Function to print minimum value in stack each time while popping
void _getMinAtPop(stack<int> st)
{
    vector<int> arr;

    getMin(st, arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<int> st = _push(arr, n);

    _getMinAtPop(st);

    return 0;
}