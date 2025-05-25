// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. 
// No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"

// Output: true

// Explanation:

// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "foo", t = "bar"

// Output: false

// Explanation:

// The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

// Example 3:

// Input: s = "paper", t = "title"

// Output: true

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, char> mp;
    char reverseMap[256] = {};  // reverseMap[c2] = c1, initialized to 0 (null)

    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i], c2 = t[i];

        if (mp.count(c1)) {
            if (mp[c1] != c2) return false;
        } else {
            if (reverseMap[c2] != 0 && reverseMap[c2] != c1) return false;

            mp[c1] = c2;
            reverseMap[c2] = c1;
        }
    }

    return true;
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isIsomorphic(s, t))
        cout << "The strings are isomorphic." << endl;
    else
        cout << "The strings are not isomorphic." << endl;

    return 0;
}
