// Problem: Maximum Product Subarray Brute Force Solution
// Time Complexity: O(n^3) - Three nested loops to calculate the product of all subarrays
// Space Complexity: O(1) - Constant space used for variables

// Approach: The brute force approach involves iterating through all possible subarrays of the input array and calculating the product of each subarray. We maintain a variable to keep track of the maximum product found during the iterations.

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
                for(int j = i; j < n; j++){
                    int product = 1;
                    for(int k = i; k <= j; k++){
                        product *= nums[k];
                    }
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