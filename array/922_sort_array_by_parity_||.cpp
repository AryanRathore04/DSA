// Leetcode 922. Sort Array By Parity II
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach: We can use two pointers to keep track of the next position for even and odd numbers. We iterate through the input array and place each number in the correct position in the output array based on its parity.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int evenIndex = 0, oddIndex = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                ans[evenIndex] = nums[i];
                evenIndex += 2;
            }
            else{
                ans[oddIndex] = nums[i];
                oddIndex += 2;
            }
        }

        return ans;
    }
};