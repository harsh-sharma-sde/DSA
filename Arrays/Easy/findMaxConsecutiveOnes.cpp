// Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int curr = 0, maxi = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) 
            curr = 0;
        else 
            curr++;

        maxi = max(maxi, curr);
    }

    return maxi;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1}; // Example input
    cout << "Maximum consecutive ones: " << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
