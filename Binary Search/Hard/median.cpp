// Given a row-wise sorted matrix of size MXN, where M is no. of rows and N is no. of columns, find the median in the given matrix.

// Note: MXN is odd.

//  Example 1:
//                     Input Format:M = 3, N = 3, matrix[][] =
//                     1 4 9 
//                     2 5 6
//                     3 8 7
//                     Result: 5
                    
//                     Explanation:  If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5
                    
//                     Example 2:
//                     Input Format:M = 3, N = 3, matrix[][] =
//                     1 3 8 
//                     2 3 4
//                     1 2 5
//                     Result: 3
                    
//                     Explanation:  If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. So, median = 3


                                    
#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}

// Complexity Analysis

// Time Complexity: O(log(109)) X O(M(logN)), where M = number of rows in the given matrix, N = number of columns in the given matrix

// Reason: Our search space lies between [0, 109] as the min(matrix) can be 0 and the max(matrix) can be 109. We are applying binary search in this search space and it takes O(log(109)) time complexity. Then we call countSmallEqual() function for every ‘mid’ and this function takes O(M(logN)) time complexity.

// Space Complexity : O(1) as we are not using any extra space
                                                               