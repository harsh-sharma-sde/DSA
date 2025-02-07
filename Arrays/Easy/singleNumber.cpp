// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,1]

// Output: 1

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    int xorr = 0;

    for (int i = 0; i < n; i++) {
        xorr ^= nums[i];
    }

    return xorr;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2}; // Example input
    cout << "The single number is: " << singleNumber(nums) << endl;
    return 0;
}
