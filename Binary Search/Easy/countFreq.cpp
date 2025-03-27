// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

// Examples :

// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
// Output: 4
// Explanation: target = 2 occurs 4 times in the given array so the output is 4.
// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
// Output: 0
// Explanation: target = 4 is not present in the given array so the output is 0.
// Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
// Output: 3
// Explanation: target = 12 occurs 3 times in the given array so the output is 3.

#include <iostream>
#include <vector>

using namespace std;

int start(vector<int>& nums, int target, int low, int high, bool &flag) {
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            high = mid - 1;
            flag = true;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int end(vector<int>& nums, int target, int low, int high, bool &flag) {
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            low = mid + 1;
            flag = true;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int countFreq(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    bool flag1 = false, flag2 = false;
    int st = start(arr, target, low, high, flag1);
    int en = end(arr, target, low, high, flag2);
    return flag1 || flag2 ? en - st + 1 : 0;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    cout << "Frequency of " << target << " is: " << countFreq(arr, target) << endl;
    return 0;
}
