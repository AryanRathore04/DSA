// Leetcode 162. Find Peak Element
// Problem: Find Peak Element Optimal Solution for one peak element
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: 1. Use binary search to find the peak element in the array.
// 2. Initialize low and high pointers to the start and end of the array respectively.
// 3. While low is less than or equal to high, calculate the mid index
// 4. If the mid element is greater than its neighbors, return the mid index as the peak element.
// 5. If the mid element is greater than the left neighbor, then the peak element is in the right half of the array, so we update low to mid + 1.
// 6. If the mid element is greater than the right neighbor, then the peak element is in the left half of the array, so we update high to mid - 1.
// 7. Return -1 if no peak element is found (this case will not occur as per the problem statement).

#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1, high = n-2;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] > nums[mid-1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;
    }
};