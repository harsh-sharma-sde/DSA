// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int sum = 0, maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        maxi = max(maxi, sum);

        if (sum < 0) sum = 0;  // Reset sum if it goes negative
    }

    return maxi;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;

    return 0;
}
