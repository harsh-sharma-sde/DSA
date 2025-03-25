// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > target) 
            high = mid - 1;  // Fix: Use mid - 1 instead of high--
        else if (nums[mid] < target) 
            low = mid + 1;   // Fix: Use mid + 1 instead of low++
        else 
            return mid;
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target;

    cout << "Enter target element: ";
    cin >> target;

    int result = search(nums, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
