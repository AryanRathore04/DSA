// Leetcode - 3158. XOR of numbers which appear twice

// topic: Hashing
// Time Complexity: O(n)
// Space Complexity: O(n)

// Explanation: We can find the number that appears twice by using a hash map to store the frequency of each number in the array. Then we can iterate through the numbers from 1 to 50 and check if the frequency of each number is equal to 2. If it is, we can XOR that number with the result.

#include <vector>;
#include <algorithm>;
#include <unordered_map>;
using namespace std;


class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {

        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        int xor1 = 0;

        for(int num = 1; num <= 50; num++){

            if(mpp[num] == 2){
                xor1 = xor1 ^ num;
            }
        }

        return xor1;
    }
};