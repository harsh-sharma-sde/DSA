// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number 
// of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<char, int> P;

string frequencySort(string s) {
    vector<P> vec(123);  // To hold (char, frequency) for ASCII chars up to 'z'

    for (char &ch : s) {
        int freq = vec[ch].second;
        vec[ch] = {ch, freq + 1};
    }

    auto comp = [&](P &p1, P &p2) {
        return p1.second > p2.second;
    };

    sort(begin(vec), end(vec), comp);

    string result = "";

    for (int i = 0; i <= 122; i++) {
        if (vec[i].second > 0)
            result += string(vec[i].second, vec[i].first);
    }

    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string sortedByFreq = frequencySort(input);
    cout << "String sorted by character frequency: " << sortedByFreq << endl;

    return 0;
}
