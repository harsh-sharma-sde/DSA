// You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

// Examples :

// Input: n = 2, m = 9
// Output: 3
// Explanation: 32 = 9
// Input: n = 3, m = 9
// Output: -1
// Explanation: 3rd root of 9 is not integer.
// Input: n = 1, m = 14
// Output: 14

#include <iostream>
using namespace std;

int nthRoot(int n, int m) {
    int low = 1, high = m, ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long val = 1;

        for (int i = 0; i < n; i++) val *= mid;

        if (val == m) return mid;

        else if (val < m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cout << "Enter the value of n (root): ";
    cin >> n;
    cout << "Enter the value of m (number): ";
    cin >> m;

    int result = nthRoot(n, m);

    if (result != -1)
        cout << "The " << n << "th root of " << m << " is: " << result << endl;
    else
        cout << m << " is not a perfect " << n << "th power." << endl;

    return 0;
}
