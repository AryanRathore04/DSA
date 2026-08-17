// Leetcode 35. Search Insert Position
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: The binary search algorithm works by maintaining two pointers, low and high, which represent the current search space. In each iteration, we calculate the middle index and compare the middle element with the target value. If they are equal, we return the index. If the target is greater than the middle element, we move the low pointer to mid + 1; otherwise, we move the high pointer to mid - 1. This process continues until the target is found or the search space is exhausted. If the target is not found, we return the index where it would be inserted in order.


#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};