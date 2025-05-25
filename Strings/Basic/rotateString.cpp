// Given two strings s and goal, return true if and only if s can become goal after some number 
// of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false

#include <iostream>
#include <string>
using namespace std;

bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;

    string concatS = s + s;
    int ind = concatS.find(goal);
    return ind != string::npos;
}

int main() {
    string s, goal;
    cout << "Enter original string: ";
    cin >> s;

    cout << "Enter goal string: ";
    cin >> goal;

    if (rotateString(s, goal))
        cout << "Yes, goal is a rotation of the original string." << endl;
    else
        cout << "No, goal is not a rotation of the original string." << endl;

    return 0;
}
