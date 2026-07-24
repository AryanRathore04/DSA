// Problem: 560. Subarray Sum Equals K
// Time Complexity: O(n) - Single pass through the array
// Space Complexity: O(n) - Hash map to store prefix sums and their counts

// Explanation: We use a hash map to store the count of each prefix sum encountered. For each element in the array, we calculate the current prefix sum and check if there exists a prefix sum that, when subtracted from the current prefix sum, equals K. If such a prefix sum exists, it means there are subarrays that sum to K. We update the count accordingly and also update the hash map with the current prefix sum.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int preSum = 0, count = 0;

        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;

            count += mpp[remove];
            mpp[preSum]++;
        }

        return count;
    }
};