// Leetcode 217. Contains Duplicate
// Topic: Arrays
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

// Explanation: The function sorts the input vector of integers and then checks for any adjacent duplicate elements. If a duplicate is found, it returns true; otherwise, it returns false after checking all elements.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
};