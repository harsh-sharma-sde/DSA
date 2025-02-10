// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    mp[nums[0]] = 0;

    for (int i = 1; i < n; i++) {
        if (mp.find(target - nums[i]) != mp.end()) {
            ans.push_back(i);
            ans.push_back(mp[target - nums[i]]);
            return ans;
        }
        mp[nums[i]] = i;
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No valid pair found." << endl;
    }
    
    return 0;
}