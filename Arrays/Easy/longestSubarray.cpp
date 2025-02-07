// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

// Examples:

// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6
// Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int n = arr.size(), sum = 0, maxi = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == k) {
            maxi = i + 1;
        }

        if (mp.find(sum - k) != mp.end()) {
            maxi = max(maxi, i - mp[sum - k]);
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxi;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 5, 3}; // Example input
    int k = 5;

    cout << "Length of the longest subarray with sum " << k << " is: " 
         << longestSubarray(arr, k) << endl;

    return 0;
}
