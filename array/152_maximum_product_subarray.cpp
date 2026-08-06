// Leetcode 152. Maximum Product Subarray
// Time Complexity: O(n) - Single pass through the array to calculate the maximum product
// Space Complexity: O(1) - Constant space used for variables

// Approach: The optimal approach involves iterating through the input array while maintaining two variables to track the maximum and minimum products at each index. This is necessary because a negative number can turn a minimum product into a maximum product. We update the maximum product found during the iterations and return it at the end.

#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1; 
        int suf = 1;
        int ans = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;

            pre = pre * nums[i];
            suf = suf * nums[n - 1 - i];
            ans = max(ans, max(pre, suf));
        }

        return ans;
    }
};