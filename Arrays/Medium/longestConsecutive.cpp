// Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Examples:

// Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
// Output: 6
// Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int>& arr) {
    int n = arr.size();
    int maxi = 0;
    unordered_map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        mp[arr[i]] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        
        if (mp[arr[i]] == 0) {
            mp[arr[i]] = 1;
            int num = arr[i];
            
            while (true) {
                num--;
                
                if (mp.find(num) != mp.end()) {
                    cnt++;
                    mp[num] = 1;
                } 
                else break;
            }
            
            maxi = max(maxi, cnt);
        }
    }
    
    return maxi;
}

int main() {
    vector<int> arr;
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    int result = longestConsecutive(arr);
    cout << "Length of the longest consecutive sequence: " << result << endl;
    
    return 0;
}
