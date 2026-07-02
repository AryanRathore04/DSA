// Leetcode 31. Next Permutation
// Time Complexity: O(3N)
// Space Complexity: O(1)

// Approach: We can find the next greater permutation by following these steps:
// 1. Traverse the array from the end to find the first decreasing element (let's call it A[ind]).
// 2. If no such element is found, reverse the entire array to get the smallest permutation.
// 3. If such an element is found, traverse the array from the end again to find the first element that is greater than A[ind] and swap them.
// 4. Finally, reverse the subarray from ind + 1 to the end of the array
// 5. Return the modified array as the next greater permutation.

#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n-1; i > ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
    }
};