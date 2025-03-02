// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int i = 0, n = nums.size();
    sort(nums.begin(), nums.end());

    while (i < n - 3) {
        long long sum = nums[i];
        int j = i + 1;

        while (j < n - 2) {
            sum += nums[j];
            int left = j + 1, right = n - 1;

            while (left < right) {
                sum += (nums[left] + nums[right]);

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    left++;
                }
                sum = nums[i] + nums[j];
            }

            j++;
            while (j < n && nums[j] == nums[j - 1]) j++;
            sum = nums[i];
        }

        i++;
        while (i < n && nums[i] == nums[i - 1]) i++;
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets summing to " << target << ":\n";
    for (const auto& quad : result) {
        cout << "[";
        for (size_t i = 0; i < quad.size(); i++) {
            cout << quad[i] << (i < quad.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    return 0;
}