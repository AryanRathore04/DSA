// Count Subarrays with Sum K - Optimal Approach
// Time Complexity: O(n) - Single pass through the array
// Space Complexity: O(n) - Hash map to store prefix sums and their counts

// Approach: Use a hash map to store the count of prefix sums. For each element in the array, calculate the current prefix sum and check if there exists a prefix sum that, when subtracted from the current prefix sum, equals K. If such a prefix sum exists, it means there are subarrays that sum to K. Update the count accordingly and also update the hash map with the current prefix sum.

#include<iostream>
#include<vector>
#include<unordered_map>
#define mpp unordered_map
using namespace std;

class Solution {
    public:
    int findAllSubarraysWithGivenSum(vector<int>& nums, int k){
        mpp<int, int> mpp;
        mpp[0] = 1; // Initialize the map with sum 0 having one occurrence
        int preSum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i]; // Update the prefix sum

            int remove = preSum - k; // Calculate the required prefix sum to find

            count += mpp[remove]; // Add the count of occurrences of the required prefix sum

            mpp[preSum]++; // Update the map with the current prefix sum
        }


        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, -3, 1, 1, 1};
    int k = 3;
    int result = solution.findAllSubarraysWithGivenSum(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;
    return 0;
}

