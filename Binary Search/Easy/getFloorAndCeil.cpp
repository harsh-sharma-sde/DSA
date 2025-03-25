// Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

// Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
// Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

// Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.

// Examples:

// Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
// Output: 6, 8
// Explanation: Floor of 7 is 6 and ceil of 7 is 8.
// Input: x = 10 , arr[] = [5, 6, 8, 8, 6, 5, 5, 6]
// Output: 8, -1
// Explanation: Floor of 10 is 8 but ceil of 10 is not possible.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    int floor = -1, ceil = -1;

    for (int num : arr) {
        if (num == x) {
            return {x, x};  // If exact match, both floor and ceil are x
        }
        if (num < x && (floor == -1 || num > floor)) {
            floor = num;  // Update floor to the largest number <= x
        }
        if (num > x && (ceil == -1 || num < ceil)) {
            ceil = num;  // Update ceil to the smallest number >= x
        }
    }

    return {floor, ceil};
}

int main() {
    vector<int> arr = {12, 4, 7, 10, 3, 20, 15}; // Unsorted array
    int x;

    cout << "Enter the number: ";
    cin >> x;

    vector<int> result = getFloorAndCeil(x, arr);

    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;

    return 0;
}
