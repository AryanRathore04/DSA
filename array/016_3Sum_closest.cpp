// Leetcode 16. 3Sum Closest
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Approach: The optimized approach involves sorting the array and then using two pointers to find pairs that sum up to the negative of the fixed number. This reduces the time complexity from O(n^3) to O(n^2). We also skip duplicates to ensure unique triplets are found.

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                int difClo = abs(closest - target);
                int difSum = abs(sum - target);

                if (difClo > difSum) {
                    closest = sum;
                }

                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    return sum;
                }
            }
        }

        return closest;
    }
};