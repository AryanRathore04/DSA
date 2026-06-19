// Leetcode 136. Single Number
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)

// Explanation: The idea is to use the XOR operation. The XOR of a number with itself is 0, and the XOR of a number with 0 is the number itself. Therefore, if we XOR all the numbers in the array, the numbers that appear twice will cancel each other out, leaving only the single number.

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for(int i = 0; i < nums.size(); i++){
            xor1 = xor1 ^ nums[i];
        }

        return xor1;
    }
};