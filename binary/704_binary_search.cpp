// Leetcode 704. Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(log n)

// Approach: The binary search algorithm works by maintaining two pointers, low and high, which represent the current search space. In each recursive call, we calculate the middle index and compare the middle element with the target value. If they are equal, we return the index. If the target is greater than the middle element, we recursively search in the right half of the array; otherwise, we search in the left half. This process continues until the target is found or the search space is exhausted.

#include <vector>
using namespace std;

class Solution {
public:
    int bs(vector<int>& nums, int low, int high, int target){
        if(low > high) return -1;

        int mid = low + (high - low) / 2;

        if(nums[mid] == target){
            return mid;
        }
        else if(target > nums[mid]){
            return bs(nums, mid + 1, high, target);
        }

        return bs(nums, low, mid - 1, target);
    }

    int search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size() - 1, target);
    }
};