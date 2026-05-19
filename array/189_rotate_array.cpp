// 189. Rotate Array
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)   

// Idea:
// 1. Reverse the whole array
// 2. Reverse the first k elements
// 3. Reverse the remaining n-k elements    
// Example:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Step 1: Reverse the whole array -> [7,6,5,4,3,2,1]
// Step 2: Reverse the first k elements -> [5,6,7,4,3,2,1]
// Step 3: Reverse the remaining n-k elements -> [5,6,7,1,2,3,4]


#include <vector>;
#include <algorithm>;
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin()+ k);

        reverse(nums.begin() + k, nums.end());
    }
};