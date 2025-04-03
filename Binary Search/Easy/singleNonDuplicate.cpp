// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    if (nums[0] != nums[1]) return nums[0];

    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];

        else if (mid % 2 != 0) {
            if (nums[mid] == nums[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }
        else {
            if (nums[mid] == nums[mid - 1]) high = mid - 1;
            else low = mid + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << "Single non-duplicate element: " << singleNonDuplicate(nums) << endl;
    return 0;
}
