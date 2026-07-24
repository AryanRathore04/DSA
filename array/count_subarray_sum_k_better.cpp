// Count Subarrays with Sum K - Better Approach
// Time Complexity: O(n^2) - Two nested loops to calculate the sum of subarrays
// Space Complexity: O(1) - Constant space used for variables

// Approach: Instead of calculating the sum of all subarrays using three nested loops, we can use two nested loops. The outer loop selects the starting index of the subarray, and the inner loop calculates the sum of the subarray starting from that index. If the sum equals K, we increment the count.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
    int countSubarrays(vector<int>& nums, int k){
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];

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