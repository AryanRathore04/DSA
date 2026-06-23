// Leetcode 1. Two Sum
// Time Complexity: O(n)
// Space Complexity: O(n)

// Explanation: We can use a hash map to store the numbers we have seen so far. For each number, we check if the complement (target - current number) exists in the hash map. If it does, we return the indices of the two numbers. If not, we add the current number and its index to the hash map.


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            int more = target - a;

            if(mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }

            mpp[a] = i;
        }
        return {};
    }
};