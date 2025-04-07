// Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

// Floor value of any number is the greatest Integer which is less than or equal to that number

// Examples:

// Input: n = 4
// Output: 2
// Explanation: Since, 4 is a perfect square, so its square root is 2.
// Input: n = 11
// Output: 3
// Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.
// Input: n = 1
// Output: 1

#include <iostream>
using namespace std;

int floorSqrt(int n) {
    int low = 1, high = n, ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;

        if (val == n) {
            ans = mid;
            break;
        } else if (val < n) {
            if (mid > ans) {
                ans = mid;
            }
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = floorSqrt(n);
    cout << "The floor square root of " << n << " is: " << result << endl;

    return 0;
}
