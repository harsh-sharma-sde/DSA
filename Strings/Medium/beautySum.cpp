// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

 

// Example 1:

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
// Example 2:

// Input: s = "aabcbaa"
// Output: 17

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int beautySum(string s) {
    int n = s.length(), sum = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> freq(26, 0);

        for (int j = i; j < n; ++j) {
            freq[s[j] - 'a']++;

            int mx = 0, mn = INT_MAX;

            for (int k = 0; k < 26; ++k) {
                if (freq[k] > 0) {
                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }
            }

            sum += (mx - mn);
        }
    }

    return sum;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = beautySum(input);
    cout << "Beauty sum of all substrings: " << result << endl;

    return 0;
}
