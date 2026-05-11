// LeetCode 283
// Move Zeroes
// Topic: Arrays, Two Pointers
// Pattern: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

// Idea:
// Use two pointers to move non-zero elements to the front of the array
// and fill the remaining positions with zeros.


#include <vector>;
#include <algorithm>;
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[k] = nums[i];
                k++;
            }
        }

        for(int j = k; j < nums.size(); j++){
            nums[j] = 0;
        }
    }
};