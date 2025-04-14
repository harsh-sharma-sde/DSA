// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

// Example 1:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
// Example 2:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
// Output: -1
// Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
// Example 3:

// Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
// Output: 12
// Explanation: We need 2 bouquets each should have 3 flowers.
// Here is the garden after the 7 and 12 days:
// After day 7: [x, x, x, x, _, x, x]
// We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
// After day 12: [x, x, x, x, x, x, x]
// It is obvious that we can make two bouquets in different ways.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool checkMDays(vector<int>& bloomDay, int m, int k, int days) {
    int cnt = 0;

    for(int i=0; i<bloomDay.size(); i++){
        if(bloomDay[i] <= days){
            cnt++;
        } else cnt = 0;

        if(cnt >= k){
            m--;
            cnt = 0;
        }

        if(m <= 0){
            return true;
        }
    }

    if(m <= 0){
        return true;
    }

    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size(), ans = INT_MAX;
    if(k > 1 && m + k > n) return -1;

    long long int prod = m*k;
    
    if(prod > n) return -1;

    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int low = *min_element(bloomDay.begin(), bloomDay.end());

    while(low <= high){
        int mid = low + (high - low)/2;

        bool isPossible = checkMDays(bloomDay, m, k, mid);

        if(isPossible){
            ans = min(ans, mid);
            high = mid-1;
        }

        else low = mid+1;
    }

    return ans;
}

int main() {
    // Test case 1
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3, k1 = 1;
    cout << "Test case 1: " << minDays(bloomDay1, m1, k1) << endl;  // Output: 3

    // Test case 2
    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    int m2 = 3, k2 = 2;
    cout << "Test case 2: " << minDays(bloomDay2, m2, k2) << endl;  // Output: -1

    // Test case 3
    vector<int> bloomDay3 = {7, 7, 7, 7, 12, 7, 7};
    int m3 = 2, k3 = 3;
    cout << "Test case 3: " << minDays(bloomDay3, m3, k3) << endl;  // Output: 12

    // Test case 4
    vector<int> bloomDay4 = {1000000000, 1000000000};
    int m4 = 1, k4 = 1;
    cout << "Test case 4: " << minDays(bloomDay4, m4, k4) << endl;  // Output: 1000000000

    // Test case 5
    vector<int> bloomDay5 = {1, 2, 4, 9, 3, 4, 1};
    int m5 = 2, k5 = 2;
    cout << "Test case 5: " << minDays(bloomDay5, m5, k5) << endl;  // Output: 4

    return 0;
}