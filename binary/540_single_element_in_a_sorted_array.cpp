// Leetcode 540: Single Element in a Sorted Array
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: 1. Initialize low and high pointers to the start and end of the array respectively.
// 2. While low is less than or equal to high, calculate the mid index
// 3. If the mid element is not equal to its neighbors, then it is the single element, so we return it
// 4. If the mid element is equal to its left neighbor and mid is odd, or if the mid element is equal to its right neighbor and mid is even, then the single element is in the right half of the array, so we update low to mid + 1
// 5. Otherwise, the single element is in the left half of the array, so we update high to mid - 1
// 6. Return -1 if no single element is found (this line will never be reached if the input is valid as per the problem statement)

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1, high = n-2;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            // We are on left side
            if(mid % 2 == 1 && nums[mid] == nums[mid-1] || mid % 2 == 0 && nums[mid] == nums[mid+1]){
                low = mid + 1;
            }
            // We are on right side
            else{
                high = mid - 1;
            }
        }

        return -1;
    }
};