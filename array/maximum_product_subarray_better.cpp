// Problem: Maximum Product Subarray Better Solution
// Time Complexity: O(n^2) - Two nested loops to calculate the product of all subarrays
// Space Complexity: O(1) - Constant space used for variables

// Approach: The better approach involves iterating through the input array and calculating the product of subarrays starting from each index. We maintain a variable to keep track of the maximum product found during the iterations. This reduces the number of nested loops compared to the brute force solution.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums){
            int n = nums.size();
            int maxi = INT_MIN;

            for(int i = 0; i < n; i++){
                int product = 1;
                for(int j = i; j < n; j++){
                    product *= nums[j];
                    maxi = max(maxi, product);
                }
            }
            return maxi;
        }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, -2, 4};
    int result = solution.maxProduct(nums);
    cout << "Maximum product subarray: " << result << endl; // Output: 6
    return 0;
}