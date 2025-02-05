// Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

// Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
// Examples:

// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
// Output: 1 2 3 4 5 6 7
// Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

#include <iostream>
#include <vector>

using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> ans;
    int m = a.size(), n = b.size();
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (ans.empty() || ans.back() != a[i]) 
                ans.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            if (ans.empty() || ans.back() != b[j]) 
                ans.push_back(b[j]);
            j++;
        } else {  // a[i] == b[j]
            if (ans.empty() || ans.back() != a[i]) 
                ans.push_back(a[i]);
            i++; j++;
        }
    }

    while (i < m) {
        if (ans.empty() || ans.back() != a[i]) 
            ans.push_back(a[i]);
        i++;
    }

    while (j < n) {
        if (ans.empty() || ans.back() != b[j]) 
            ans.push_back(b[j]);
        j++;
    }

    return ans;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 5, 6, 7};

    vector<int> result = findUnion(a, b);

    cout << "Union of the two sorted arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
