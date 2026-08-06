// Problem: Maximum Product Subarray Optimal Solution
// Time Complexity: O(n) - Single pass through the array to calculate the maximum product
// Space Complexity: O(1) - Constant space used for variables

// Approach: The optimal approach involves iterating through the input array while maintaining two variables to track the maximum and minimum products at each index. This is necessary because a negative number can turn a minimum product into a maximum product. We update the maximum product found during the iterations and return it at the end.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int subarrayWithMaxProduct(vector<int> &arr){
            int pre = 1, suf = 1, ans = INT_MIN;
            int n = arr.size();

            for(int i = 0; i < n; i++){
                if(pre == 0) pre = 1;
                if(suf == 0) suf = 1;

                pre = pre * arr[i];
                suf = suf * arr[n - 1 - i];
                ans = max(ans, max(pre, suf));
            }
            return ans;
        }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, -2, 4};
    int result = solution.subarrayWithMaxProduct(nums);
    cout << "Maximum product subarray: " << result << endl; // Output: 6
    return 0;
}