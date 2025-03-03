#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLen(vector<int>& arr) {
    int n = arr.size();
    int ans = 0, sum = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        if (mp.find(sum) != mp.end()) {
            ans = max(ans, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = maxLen(arr);
    cout << "Length of the longest subarray with sum 0: " << result << endl;
    
    return 0;
}
