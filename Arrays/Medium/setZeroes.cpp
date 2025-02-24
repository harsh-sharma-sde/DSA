// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix[0].size();
    int n = matrix.size();
    if(n==1 && m==1) return;
    int one = matrix[0][0];
    bool row = false, col = false;

    for(int i=1; i<n; i++){
        if(matrix[i][0] == 0){
           one = 0;
           row = true;
        } 
    }

    for(int j=1; j<m; j++){
        if(matrix[0][j] == 0){
           one = 0;
           col = true;
        } 
    }

    for(int i=1; i<n; i++){
       for(int j=1; j<m; j++){
        if(matrix[i][j] == 0){
            matrix[i][0] = 0;
            matrix[0][j] = 0;
        }
       }
    }

    for(int i=n-1; i>=1; i--){
        for(int j=m-1; j>=1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    for(int i=n-1; i>0; i--){
        if(row || matrix[0][0] == 0){
            matrix[i][0] = 0;
        }
    }

    for(int j=m-1; j>0; j--){
        if(col || matrix[0][0] == 0){
            matrix[0][j] = 0;
        }
    }

    matrix[0][0] = one;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:" << endl;
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    setZeroes(matrix);

    cout << "\nMatrix after setting zeroes:" << endl;
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
