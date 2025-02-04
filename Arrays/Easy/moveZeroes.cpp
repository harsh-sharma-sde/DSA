// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int zero = -1;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0 && zero == -1) {
            zero = i;
        } else if (nums[i] != 0 && zero > -1) {
            swap(nums[i], nums[zero]);

            while (zero < n && nums[zero] != 0) zero++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12}; // Example input

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
