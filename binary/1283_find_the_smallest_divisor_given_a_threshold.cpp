// Leetcode 1283: Find the Smallest Divisor Given a Threshold
// Time Complexity: O(n log(max)), where n is the size of the array and max is the maximum value in the array.
// Space Complexity: O(1)

// Approach: 1. Use binary search to find the smallest divisor. The search space is between 1 and the maximum value in the array.
// 2. For each mid value (potential divisor), calculate the sum of the ceiling of each element divided by mid.
// 3. If the sum is greater than the threshold, it means the divisor is too small, so we need to increase the divisor (low = mid + 1). If the sum is less than or equal to the threshold, we can try to find a smaller divisor (high = mid - 1).
// 4. Continue the binary search until low exceeds high, and return the low value, which will be the smallest divisor that satisfies the condition.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size() > threshold) return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long sum = 0;

            for(int i = 0; i < nums.size(); i++){
                sum += (nums[i] + mid - 1) / mid;
            }

            if(sum > threshold){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low;
    }
};