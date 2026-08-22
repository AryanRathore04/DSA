// Leetcode 153: Find Minimum in Rotated Sorted Array
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: We can use binary search to find the minimum element in the rotated sorted array. We will check if the left half or right half is sorted and then decide which half to search based on the values of the elements.

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

            //Left half is sorted
            if(nums[mid] >= nums[low]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else{
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }

        return ans;
    }
};