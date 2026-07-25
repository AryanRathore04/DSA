// Leetcode 974. Subarray Sums Divisible by K
// Time Complexity: O(n) - Single pass through the array
// Space Complexity: O(n) - Hash map to store prefix sums and their counts

// Approach: We use a hash map to store the count of each prefix sum modulo k encountered. For each element in the array, we calculate the current prefix sum and its remainder when divided by k. If such a remainder exists in the hash map, it means there are subarrays that sum to a multiple of k. We update the count accordingly and also update the hash map with the current remainder.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int preSum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            int remainder = preSum % k;

            if (remainder < 0)
                remainder += k;

            count += mpp[remainder];

            mpp[remainder]++;
        }

        return count;
    }
};