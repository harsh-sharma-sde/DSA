// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
 

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
// Example 2:

// Input: nums = [2,4,3,5,1]
// Output: 3
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
// (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

#include <iostream>
#include <vector>

using namespace std;

int countPairs(vector<int>& nums, int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right && nums[i] > 2LL * nums[j]) { // 2LL to handle overflow
            j++;
        }
        count += (j - (mid + 1));
    }

    return count;
}

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(nums[j]);
        j++;
    }

    for (int k = left; k <= right; k++) {
        nums[k] = temp[k - left];
    }
}

int mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = mergeSort(nums, left, mid);
    count += mergeSort(nums, mid + 1, right);
    count += countPairs(nums, left, mid, right);
    merge(nums, left, mid, right);

    return count;
}

int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    int result = reversePairs(nums);
    cout << "Number of reverse pairs: " << result << endl;
    return 0;
}
