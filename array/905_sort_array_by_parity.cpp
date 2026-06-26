// Leetcode 905. Sort Array By Parity
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach: We can create a new array and first put all even numbers in it, then put all odd numbers in it. Finally, we return the new array.

#include <vector>
using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       vector<int> ans;

        // first put all even numbers
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                ans.push_back(nums[i]);
            }
        }

        // then put all odd numbers
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 != 0){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};