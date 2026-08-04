#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 1;
        int hi = arr.size() - 2;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    int n;
    cout << "Enter size of mountain array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int peak = obj.peakIndexInMountainArray(arr);

    cout << "Peak Index = " << peak << endl;
    cout << "Peak Element = " << arr[peak] << endl;

    return 0;
}