// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int forwardProd = 1;
    int backwardProd = 1;
    int n = nums.size(), maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        forwardProd *= nums[i];
        maxi = max(maxi, forwardProd);
        if (forwardProd == 0) {
            forwardProd = 1;
        }
    }

    for (int j = n - 1; j >= 0; j--) {
        backwardProd *= nums[j];
        maxi = max(maxi, backwardProd);
        if (backwardProd == 0) {
            backwardProd = 1;
        }
    }

    return maxi;
}

int main() {
    vector<int> nums = {2, 3, -2, 4}; // Example input
    cout << "Maximum Product Subarray: " << maxProduct(nums) << endl;
    return 0;
}
