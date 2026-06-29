// Problem: Rearrange Array Elements by Sign
// Time Complexity: O(2n)
// Space Complexity: O(n)

// Approach:
// 1. Create two vectors, one for positive numbers and one for negative numbers.
// 2. Iterate through the input array and separate the positive and negative numbers into their respective vectors.
// 3. Iterate through the input array again and fill it with alternating positive and negative numbers from the two vectors.
// 4. Return the rearranged array.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public: 
    vector<int> rearrangeArray(vector<int>& nums){
        vector<int> pos;
        vector<int> neg;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }
        for(int i = 0; i < nums.size() / 2; i++){
            nums[i*2] = pos[i];
            nums[i*2 + 1] = neg[i];
        }
        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> result = solution.rearrangeArray(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}