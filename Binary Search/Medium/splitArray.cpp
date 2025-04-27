#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int cntSubArr(vector<int>& nums, int mid, int n) {
    int cnt = 1, sum = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i];

        if(sum > mid) {
            cnt++;
            sum = nums[i];
        } else if(sum == mid) {
            sum = 0;
            if(i < n - 1) cnt++;
        }
    }

    return cnt;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    long long high = 0;
    int n = nums.size(), ans = INT_MAX;

    for(int i = 0; i < n; i++) {
        high += nums[i];
    }

    if(nums.size() == 1 || k == 1) return high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int subArr = cntSubArr(nums, mid, n);

        cout << "Trying mid = " << mid << ", number of subarrays = " << subArr << endl;

        if(subArr <= k) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    int result = splitArray(nums, k);
    cout << "Minimum largest sum among " << k << " subarrays is: " << result << endl;

    return 0;
}
