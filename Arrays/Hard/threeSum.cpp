#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size(), i = 0, sum = 0;
    sort(nums.begin(), nums.end());

    while (i < n - 2) {
        int j = i + 1, k = n - 1;

        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
            else if (sum > 0) {
                k--;
                while (j < k && nums[k] == nums[k + 1]) k--;
            } 
            else {
                j++;
                while (j < k && nums[j] == nums[j - 1]) j++;
            } 
        }

        i++;
        while (i < n - 2 && nums[i] == nums[i - 1]) i++;
    }

    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    cout << "Unique triplets that sum up to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    return 0;
}
