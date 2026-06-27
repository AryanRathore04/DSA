// 268. Missing Number
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)

// Explanation: We can find the missing number by the XOR method. We will XOR all the numbers from 0 to N and also XOR all the numbers in the given array. The result will be the missing number.


#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int xor1 = 0;
        int xor2 = 0;

        for(int i = 0; i < nums.size(); i++){
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ (i);
        }

        xor1 = xor1 ^ N;

        return xor1 ^ xor2;
    }
};