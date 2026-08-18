// LeeCode 34. Find First and Last Position of Element in Sorted Array
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: The binary search algorithm is used to find the first and last occurrence of a target value in a sorted array. Two separate functions, firstOccure and lastOccure, are implemented to find the first and last positions respectively. Each function maintains two pointers, low and high, to represent the current search space. In each iteration, the middle index is calculated and compared with the target value. If they are equal, the index is stored as a potential answer, and the search continues in the left half for firstOccure or in the right half for lastOccure. If the target is greater than the middle element, the low pointer is moved to mid + 1; otherwise, the high pointer is moved to mid - 1. This process continues until the target is found or the search space is exhausted. Finally, the indices of the first and last occurrences are returned as a vector.

#include <vector>
using namespace std;

class Solution {
public:
    int firstOccure(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1; 

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    int lastOccure(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1; 

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccure(nums, target);
        int last = lastOccure(nums, target);

        return {first, last};
    }
};