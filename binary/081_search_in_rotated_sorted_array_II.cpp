// Leetcode 81. Search in Rotated Sorted Array II
// Time Complexity: O(log n) in average case, O(n) in worst case
// Space Complexity: O(1)

// Approach: We can use binary search to find the element in the rotated sorted array. We will check if the left half or right half is sorted and then decide which half to search based on the value of the target element. If we encounter duplicates, we will shrink the search space by moving the low and high pointers.

#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return true;

            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};