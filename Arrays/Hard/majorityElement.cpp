// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0, ele1 = INT_MAX, ele2 = INT_MIN;
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (cnt1 <= 0 && ele2 != nums[i]) {
            ele1 = nums[i];
            cnt1++;
        } else if (ele1 == nums[i]) {
            cnt1++;
        } else if (cnt2 == 0 && ele1 != nums[i]) {
            ele2 = nums[i];
            cnt2++;
        } else if (ele2 == nums[i]) {
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    if (ele1 != INT_MAX) {
        cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (ele1 == nums[i]) cnt1++;
        }
        if (cnt1 > n / 3) ans.push_back(ele1);
    }

    if (ele2 != INT_MIN) {
        cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (ele2 == nums[i]) cnt2++;
        }
        if (cnt2 > n / 3) ans.push_back(ele2);
    }

    return ans;
}

int main() {
    vector<int> nums = {3, 3, 2, 2, 2, 3, 3, 4};
    vector<int> result = majorityElement(nums);

    cout << "Majority elements (appearing more than n/3 times): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
