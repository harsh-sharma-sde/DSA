// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

// Example 1:

// Input: s = "(1+(2*3)+((8)/4))+1"

// Output: 3

// Explanation:

// Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:

// Input: s = "(1)+((2))+(((3)))"

// Output: 3

// Explanation:

// Digit 3 is inside of 3 nested parentheses in the string.

// Example 3:

// Input: s = "()(())((()()))"

// Output: 3

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxDepth(string s) {
    int cnt = 0;
    int n = s.length(), maxi = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') cnt++;
        maxi = max(maxi, cnt);
        if (s[i] == ')') cnt--;
    }

    return maxi;
}

int main() {
    string input;
    cout << "Enter a parentheses string: ";
    cin >> input;

    int depth = maxDepth(input);
    cout << "Maximum nesting depth: " << depth << endl;

    return 0;
}
