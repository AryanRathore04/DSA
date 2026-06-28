// Leetcode 918. Maximum Sum Circular Subarray
// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach: Kadane's Algorithm
// 1. Find the maximum subarray sum using Kadane's algorithm.
// 2. Find the minimum subarray sum using Kadane's algorithm.
// 3. The maximum circular subarray sum will be the maximum of the two sums calculated above.
// 4. If the maximum subarray sum is negative, return it as the result. Otherwise, return the maximum of the two sums calculated above.


#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int miniSum = 0;
        int totalSum = 0;
        int maxSum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            maxSum += nums[i];
            totalSum += nums[i];
            if(maxi < maxSum){
                maxi = maxSum;
            }
            if(maxSum < 0){
                maxSum = 0;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            miniSum += nums[i];
            if(mini > miniSum){
                mini = miniSum;
            }
            if(miniSum > 0){
                miniSum = 0;
            }
        }

       
        if(maxi < 0){
            return maxi;
        }
        else {
            return max(maxi, totalSum - mini);
        }

    }
};