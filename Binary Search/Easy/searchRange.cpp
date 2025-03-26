// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

#include <iostream>
#include <vector>

using namespace std;

int start(vector<int>& nums, int target, int low, int high) {
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            high = mid - 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int end(vector<int>& nums, int target, int low, int high) {
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int st = start(nums, target, low, high);
    int en = end(nums, target, low, high);
    return {st, en};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target;
    
    cout << "Enter target value: ";
    cin >> target;
    
    vector<int> result = searchRange(nums, target);
    cout << "Start index: " << result[0] << ", End index: " << result[1] << endl;
    
    return 0;
}
