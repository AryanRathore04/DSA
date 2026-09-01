// Leetcode 410. Split Array Largest Sum
// Time Complexity: O(nlog(sum of array - max element of array))
// Space Complexity: O(1)

// Approach: 1. Initialize low as the maximum element of the array and high as the sum of all elements in the array.
// 2. Use binary search to find the minimum largest sum that can be achieved by splitting the array into k subarrays.
// 3. For each mid value, check if it's possible to split the array into k subarrays such that no subarray has a sum greater than mid using the isPossible function.
// 4. If it's possible, update high to mid, otherwise update low to mid + 1.
// 5. Continue the binary search until low is equal to high, which will be the answer.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums, int k, int mid){
        int currentSum = 0;
        int subjects = 1;

        for(int i = 0; i < nums.size(); i++){
            if(currentSum + nums[i] > mid){
                subjects++;
                currentSum = nums[i];
                if(subjects > k){
                    return false;
                }
            }else{
                currentSum += nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int m = nums.size();
        if (m < k) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low < high){
            int mid = low + (high - low) / 2;

            if(isPossible(nums, k , mid)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};