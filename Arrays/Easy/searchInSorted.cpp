// Given an array, arr[] sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false.

// Examples:

// Input: arr[] = [1, 2, 3, 4, 6], k = 6
// Output: true
// Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing), output is true.

#include <iostream>
#include <vector>

using namespace std;

bool searchInSorted(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == k) return true;
        else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return false;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int k;
    
    cout << "Enter the number to search: ";
    cin >> k;
    
    if (searchInSorted(arr, k)) {
        cout << k << " is present in the array." << endl;
    } else {
        cout << k << " is not present in the array." << endl;
    }
    
    return 0;
}
