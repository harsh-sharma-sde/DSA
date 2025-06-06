// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Sorting based on the first element of each interval
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; // Ascending order
    });

    vector<vector<int>> ans;
    vector<int> temp = intervals[0];

    int n = intervals.size();
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= temp[1]) {
            temp[1] = max(temp[1], intervals[i][1]); // Merge overlapping intervals
        } else {
            ans.push_back(temp); // Store merged interval
            temp = intervals[i];
        }
    }
    ans.push_back(temp); // Push the last interval

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> mergedIntervals = merge(intervals);

    cout << "Merged Intervals:\n";
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}
