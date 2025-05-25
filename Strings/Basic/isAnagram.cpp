// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, int> mp;

    for (int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }

    for (int i = 0; i < t.length(); i++) {
        if (!mp[t[i]] || mp[t[i]] <= 0) return false;
        else mp[t[i]]--;
    }

    return true;
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;

    return 0;
}
