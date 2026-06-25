// Leetcode Problem: 75. Sort Colors
// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach: Use three pointers to sort the array in a single pass. The first pointer (low) points to the next position for 0, the second pointer (mid) traverses the array, and the third pointer (high) points to the next position for 2. When mid encounters a 0, it swaps with low and increments both low and mid. When mid encounters a 1, it just increments mid. When mid encounters a 2, it swaps with high and decrements high.

#include <vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};