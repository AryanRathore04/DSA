// Leetcode 2149. Rearrange Array Elements by Sign
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach: We can use two pointers to keep track of the next position for positive and negative numbers. We iterate through the input array and place each number in the correct position in the output array based on its sign. 

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        return ans;
    }
};