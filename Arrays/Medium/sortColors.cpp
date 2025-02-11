// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int zero = 0, two = n - 1, i = 0;

    while (i <= two) {
        if (nums[i] == 0) {
            swap(nums[i], nums[zero]);
            zero++;
            i++;
        } else if (nums[i] == 2) {
            swap(nums[i], nums[two]);
            two--;
        } else {
            i++;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sortColors(nums);

    cout << "After sorting: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
