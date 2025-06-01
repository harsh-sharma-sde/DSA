// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        // Odd length
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }

        // Even length
        l = i; r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = longestPalindrome(input);
    cout << "Longest palindromic substring: " << result << endl;

    return 0;
}
