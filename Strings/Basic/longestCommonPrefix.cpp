// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if (n == 0) return "";

    string first = strs[0];

    for (int i = 1; i < n; i++) {
        int len = min(strs[i].length(), first.length());
        int j = 0;

        while (j < len) {
            if (first[j] != strs[i][j]) {
                first = strs[i].substr(0, j);
                break;
            }
            j++;
        }

        if (j == 0) return "";  // No common prefix
        if (first.length() > strs[i].length()) first = strs[i];
    }

    return first;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);
    if (!result.empty())
        cout << "Longest Common Prefix: " << result << endl;
    else
        cout << "No common prefix found." << endl;

    return 0;
}
