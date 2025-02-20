// You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

// Examples:

// Input: arr = [16, 17, 4, 3, 5, 2]
// Output: [17, 5, 2]
// Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leaders(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    
    int maxi = arr[n-1];
    ans.push_back(maxi);
    
    for(int i = n-2; i >= 0; i--) {
        if(arr[i] >= maxi) {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> result = leaders(arr);
    
    cout << "Leaders in the array are: ";
    for(int leader : result) {
        cout << leader << " ";
    }
    cout << endl;
    
    return 0;
}
