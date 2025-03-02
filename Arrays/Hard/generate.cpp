// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++) {
        vector<int> v;
        for (int j = 0; j <= i; j++) {
            if (j == 0) 
                v.push_back(1);
            else if (j == i) 
                v.push_back(ans[i - 1][j - 1]);
            else 
                v.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        ans.push_back(v);
    }

    return ans;
}

int main() {
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> pascalTriangle = generate(numRows);

    // Printing Pascal's Triangle
    for (const auto& row : pascalTriangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
