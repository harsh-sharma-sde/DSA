// Given an array arr[], with 0-based indexing, select any two indexes, i and j such that i < j. From the subarray arr[i...j], 
// select the smallest and second smallest numbers and add them, you will get the score for that subarray. Return the maximum 
// possible score across all the subarrays of array arr[].

// Input : arr[] = [4, 3, 1, 5, 6]
// Output : 11
// Explanation : Subarrays with smallest and second smallest are:- [4, 3] smallest = 3,second smallest = 4
// [4, 3, 1] smallest = 1, second smallest = 3
// [4, 3, 1, 5] smallest = 1, second smallest = 3
// [4, 3, 1, 5, 6] smallest = 1, second smallest = 3
// [3, 1] smallest = 1, second smallest = 3
// [3, 1, 5] smallest = 1, second smallest = 3
// [3, 1, 5, 6] smallest = 1, second smallest = 3
// [1, 5] smallest = 1, second smallest = 5
// [1, 5, 6] smallest = 1, second smallest = 5
// [5, 6] smallest = 5, second smallest = 6
// Maximum sum among all above choices is, 5 + 6 = 11.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> findLeftMin(vector<int> &arr){
    stack<int> st;
    vector<int> ans;
    st.push(-1);
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        while(st.top() > arr[i]){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(arr[i]);
    }
    return ans;
}

vector<int> findRightMin(vector<int> &arr){
    stack<int> st;
    vector<int> ans;
    st.push(-1);
    int n = arr.size();
    
    for(int i=n-1; i>=0; i--){
        while(st.top() > arr[i]){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int pairWithMaxSum(vector<int> &arr) {
    vector<int> arrMaxi;
    int sum = 0;
    vector<int> left = findLeftMin(arr);
    vector<int> right = findRightMin(arr);
    
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        arrMaxi.push_back(max(left[i], right[i]));
    }
    
    for(int i=0; i<n; i++){
        sum = max(sum, arr[i] + arrMaxi[i]);
    }
    
    return sum;
}

int main() {
    vector<int> arr = {3, 1, 6, 4, 5, 2}; // Example input
    cout << "Maximum Pair Sum: " << pairWithMaxSum(arr) << endl;
    return 0;
}


// ### **Explanation of the Code**

// This C++ program finds the maximum sum of a pair `(arr[i], x)`, where `x` is the minimum element found either to the left or right of `arr[i]`. The program consists of the following functions:

// ---

// ### **1. `findLeftMin` Function**
// This function finds the **nearest smaller element to the left** for each element in the array.

// - **Logic**:
//   - We use a **stack** to keep track of previous elements.
//   - We push `-1` initially (indicating no smaller element).
//   - As we iterate over the array:
//     - If the stack's top is greater than `arr[i]`, we pop elements until we find a smaller value.
//     - The nearest smaller element is then pushed into `ans`.
//     - The current element is pushed onto the stack for future comparisons.

// **Example Execution**:
// For `arr = [3, 1, 6, 4, 5, 2]`, the **nearest left smaller** elements are:
// ```
// Index:   0  1  2  3  4  5
// arr:    [3, 1, 6, 4, 5, 2]
// LeftMin: [-1, -1,  1,  1,  4,  1]
// ```

// ---

// ### **2. `findRightMin` Function**
// This function finds the **nearest smaller element to the right** for each element in the array.

// - **Logic**:
//   - Similar to `findLeftMin`, but we traverse **from right to left**.
//   - We use a **stack** to keep track of elements.
//   - We push `-1` initially.
//   - If the stack's top is greater than `arr[i]`, we pop elements until we find a smaller value.
//   - The nearest smaller element is stored and the current element is pushed onto the stack.
//   - Finally, the `ans` array is **reversed** to match the original input order.

// **Example Execution**:
// For `arr = [3, 1, 6, 4, 5, 2]`, the **nearest right smaller** elements are:
// ```
// Index:   0  1  2  3  4  5
// arr:    [3, 1, 6, 4, 5, 2]
// RightMin:[1, -1, 4, 2, 2, -1]
// ```

// ---

// ### **3. `pairWithMaxSum` Function**
// This function finds the **maximum sum** of an element with its nearest left or right smaller element.

// - **Steps**:
//   1. Compute `left[]` and `right[]` arrays using `findLeftMin` and `findRightMin`.
//   2. For each element, compute `arrMaxi[i] = max(left[i], right[i])`, meaning we pick the maximum between the left and right smaller elements.
//   3. Compute `sum = max(sum, arr[i] + arrMaxi[i])` for all elements.

// **Example Execution**:
// ```
// Index:   0   1   2   3   4   5
// arr:    [3,  1,  6,  4,  5,  2]
// LeftMin:[-1, -1,  1,  1,  4,  1]
// RightMin:[1, -1,  4,  2,  2, -1]
// arrMaxi:[ 1, -1,  4,  2,  4,  1]
// Sum Calculation:
// (3+1), (1+(-1)), (6+4), (4+2), (5+4), (2+1) → max = 10
// ```
// **Output:**
// ```
// Maximum Pair Sum: 10
// ```

// ---

// ### **4. `main` Function**
// - Initializes an example array `{3, 1, 6, 4, 5, 2}`.
// - Calls `pairWithMaxSum()` and prints the result.

// ---

// ### **Complexity Analysis**
// - **Each function (`findLeftMin`, `findRightMin`) runs in `O(N)`.**
// - **Finding the max sum runs in `O(N)`.**
// - **Overall Complexity: `O(N)`.**

// This makes the algorithm efficient for large inputs. 🚀