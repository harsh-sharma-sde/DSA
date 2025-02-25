#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {         
    int n = matrix.size();  
    
    // Transpose the matrix
    for(int i=0; i<n; i++){             
        for(int j=0; j<=i; j++){                 
            swap(matrix[i][j], matrix[j][i]);             
        }         
    }  
    
    // Reverse each row
    for(int i=0; i<n; i++){             
        reverse(matrix[i].begin(), matrix[i].end());         
    }     
}

void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    rotate(matrix);

    cout << "\nRotated Matrix (90 degrees clockwise):" << endl;
    printMatrix(matrix);

    return 0;
}
