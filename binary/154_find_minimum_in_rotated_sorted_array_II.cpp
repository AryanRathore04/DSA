// Leetcode 154: Find Minimum in Rotated Sorted Array II
// Time Complexity: O(log n) in average case, O(n) in worst case
// Space Complexity: O(1)

// Approach: 1. Initialize low and high pointers to the start and end of the array respectively.
// 2. While low is less than or equal to high, calculate the mid index
// 3. If the mid element is less than or equal to the high element, then the minimum element is in the left half of the array, so we update high to mid - 1 and update the answer to the minimum of the current answer and the mid element
// 4. If the mid element is greater than the high element, then the minimum element is in the right half of the array, so we update low to mid + 1 and update the answer to the minimum of the current answer and the mid element
// 5. If the mid element is equal to the high element, we cannot determine which half contains the minimum element so we decrement high by 1 and increment low by 1 to shrink the search space and continue the search
// 6. Return the answer

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                high--;
                low++;
                ans = min(ans, nums[mid]);
                continue;
            }

            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};