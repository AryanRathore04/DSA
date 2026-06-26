// Majority Element (Optimal Approach)
// Time Complexity: O(N)
// Space Complexity: O(1)

// Explanation: The algorithm uses Boyer-Moore Majority Vote Algorithm. It maintains a count and an element. If the count is 0, it updates the element. If the current element is the same as the stored element, it increments the count; otherwise, it decrements the count.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public: 
    int majorityElement(vector<int> nums){
        int cnt = 0;
        int element = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                element = nums[i];
            }
            else if(nums[i] == element){
                cnt++;
            }
            else{
                cnt--;
            }
        }
    }
};