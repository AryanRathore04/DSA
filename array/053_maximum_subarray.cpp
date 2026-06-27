// Leetcode 53. Maximum Subarray
// Time Complexity: O(n)
// Space Complexity: O(1)

// Explanation: The idea is to keep track of the maximum sum of the subarray ending at the current index. If the sum becomes negative, we reset it to zero since a negative sum would not contribute positively to any future subarray sums. We also keep track of the maximum sum encountered so far.

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(maxi < sum){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }

        return maxi;
    }
};