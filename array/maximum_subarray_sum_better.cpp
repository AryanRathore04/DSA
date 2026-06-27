// Maximum Subarray Sum Better Solution
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Explanation: The problem is to find the contiguous subarray within a one-dimensional array of numbers which has the largest sum. The better solution involves using two nested loops to generate all possible subarrays and calculate their sums, keeping track of the maximum sum found, and returning that maximum sum at the end. This approach has a time complexity of O(n^2) due to the two nested loops used to generate all subarrays and calculate their sums.

#include <vector>
using namespace std;

class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }
};