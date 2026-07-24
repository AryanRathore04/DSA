// Count Subarrays with Sum K - Brute Force Approach
// Time Complexity: O(n^3) - Three nested loops to calculate the sum of all subarrays
// Space Complexity: O(1) - Constant space used for variables

// Approach: Check all possible subarrays and calculate their sums to find those equal to K.


#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
    int countSubarrays(vector<int>& nums, int k){
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int sum = 0;
                for(int l = i; l <=j; l++){
                    sum += nums[l];
                }

                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    int result = solution.countSubarrays(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;
    return 0;
}