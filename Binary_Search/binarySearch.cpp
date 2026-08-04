#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int ans = search(nums, target);

    if (ans != -1)
        cout << "Target found at index: " << ans << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}