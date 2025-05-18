// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, 
// and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

#include <iostream>
#include <vector>
using namespace std;

int findMaxInCol(vector<vector<int>>& mat, int n, int col) {
    int maxi = -1, ind = -1;

    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxi) {
            maxi = mat[i][col];
            ind = i;
        }
    }

    return ind;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m - 1;
    vector<int> ans;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = findMaxInCol(mat, n, mid);

        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;

        if (mat[row][mid] > left && mat[row][mid] > right) {
            ans.push_back(row);
            ans.push_back(mid);
            return ans;
        } else if (left > mat[row][mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    vector<int> peak = findPeakGrid(mat);
    cout << "Peak element is at: [" << peak[0] << ", " << peak[1] << "]" << endl;
    cout << "Value: " << mat[peak[0]][peak[1]] << endl;

    return 0;
}
