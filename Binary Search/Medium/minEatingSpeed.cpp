// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long returnHours(vector<int>& piles, int b){
    int n = piles.size();
    long long hrs = 0;

    for(int i = 0; i < n; i++){
        if(piles[i] >= b){
            int q = piles[i] / b;
            hrs += q;
        }

        if(piles[i] % b) hrs++;
    }

    return hrs;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int high = *max_element(piles.begin(), piles.end());
    int low = 1, ans = INT_MAX - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        long long hours = returnHours(piles, mid);

        if(hours <= h){
            ans = min(ans, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
