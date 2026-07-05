// Leetcode 1299. Replace Elements with Greatest Element on Right Side
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach:
// 1. Initialize a variable to keep track of the maximum element seen so far, starting with -1 (since the last element will be replaced with -1).
// 2. Iterate through the array from right to left.
// 3. For each element, store the current maximum in the result array and update the maximum if the current element is greater.
// 4. Return the result array.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi = -1;
        int n = arr.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = maxi;
            maxi = max(maxi, arr[i]);
        }
        return ans;
    }
};