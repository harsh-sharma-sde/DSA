// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 1) return nums[0] == k; 

    unordered_map<int, int> mp;
    mp[0] = 1;

    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (mp.find(sum - k) != mp.end()) cnt += mp[sum - k];
        mp[sum]++;
    }
    return cnt;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, -2, 5}; // Example array
    int k = 5; // Example target sum
    
    int result = subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;
    
    return 0;
}
