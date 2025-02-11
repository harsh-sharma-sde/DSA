// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int cnt = 1, digit = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] != digit) {
            cnt--;
        } else {
            cnt++;
        }

        if (cnt <= 0) {
            cnt = 1;
            digit = nums[i];
        }
    }

    return digit;
}

int main() {
    vector<int> nums = {3, 2, 3};

    cout << "Majority Element: " << majorityElement(nums) << endl;

    return 0;
}
