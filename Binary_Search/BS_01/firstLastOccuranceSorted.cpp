#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    int first = -1;
    int last = -1;

    // Find first occurrence
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) {
            first = mid;
            hi = mid - 1;
        }
        else if (nums[mid] > target) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    // Find last occurrence
    lo = 0;
    hi = nums.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) {
            last = mid;
            lo = mid + 1;
        }
        else if (nums[mid] > target) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    return {first, last};
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

    vector<int> ans = searchRange(nums, target);

    cout << "First occurrence: " << ans[0] << endl;
    cout << "Last occurrence: " << ans[1] << endl;

    return 0;
}