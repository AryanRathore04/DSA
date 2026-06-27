// Maximum Subarray Sum Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(1)

// Explanation: The problem is to find the contiguous subarray within a one-dimensional array of numbers which has the largest sum. The optimal solution uses Kadane's Algorithm, which iterates through the array while maintaining a running sum and updating the maximum sum found so far. If the running sum becomes negative, it is reset to zero, as a negative sum would not contribute to a maximum subarray. This approach has a time complexity of O(n) and a space complexity of O(1).

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class solution {
    public:
    long long maxSubarraySum(vector<int>& nums){
        long long sum = 0, maxi = LONG_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(sum > maxi){
                maxi = sum;
            }

            if(sum < 0){
                sum = 0;
            }
        }

        return maxi;
    }
};