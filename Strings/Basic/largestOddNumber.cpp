// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a 
// non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
// Example 2:

// Input: num = "4206"
// Output: ""
// Explanation: There are no odd numbers in "4206".
// Example 3:

// Input: num = "35427"
// Output: "35427"
// Explanation: "35427" is already an odd number.

#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {
    int n = num.length(), ind = -1;

    for (int i = n - 1; i >= 0; i--) {
        int number = num[i] - '0';
        if (number % 2) {
            ind = i;
            break;
        }
    }

    if (ind > -1) return num.substr(0, ind + 1);

    return "";
}

int main() {
    string num;
    cout << "Enter a number: ";
    cin >> num;

    string result = largestOddNumber(num);
    if (!result.empty())
        cout << "Largest odd number from left prefix: " << result << endl;
    else
        cout << "No odd number found in the string." << endl;

    return 0;
}


