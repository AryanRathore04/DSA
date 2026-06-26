// Problem: Majority Element
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   vector<int> majorityElement(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        int cnt = 0;

        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == nums[i]){
                cnt++;
            }
        }

        if(cnt > nums.size() / 2) return {nums[i]};
    }
    return {};
   }
};
