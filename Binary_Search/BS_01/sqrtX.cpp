#include <iostream>
using namespace std;

int mySqrt(int x) {
    long long lo = 0;
    long long hi = x;
    long long ans = 0;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        if (mid * mid == x) {
            return mid;
        }
        else if (mid * mid > x) {
            hi = mid - 1;
        }
        else {
            ans = mid;
            lo = mid + 1;
        }
    }

    return ans;
}

int main() {
    int x;

    cout << "Enter a number: ";
    cin >> x;

    cout << "Square root (integer part): " << mySqrt(x) << endl;

    return 0;
}