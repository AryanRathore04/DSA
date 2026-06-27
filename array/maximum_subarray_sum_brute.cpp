// Problem: Maximum Subarray Sum Brute Force
// Time Complexity: O(n^3)
// Space Complexity: O(1)

// Explanation: The problem is to find the contiguous subarray within a one-dimensional array of numbers which has the largest sum. The brute force solution involves checking all possible subarrays and calculating their sums, keeping track of the maximum sum found, and returning that maximum sum at the end. This approach has a time complexity of O(n^3) due to the three nested loops used to generate all subarrays and calculate their sums.


#include <vector>
using namespace std;

class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int sum = 0;
                for(int k = i; k < j; k++){
                    sum += nums[k];
                }
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }
};