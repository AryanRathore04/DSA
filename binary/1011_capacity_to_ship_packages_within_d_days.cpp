// Leetcode Problem: 1011. Capacity To Ship Packages Within D Days
// Time Complexity: O(n log(sum(weights) - max(weights))), where n is the number of packages. The binary search runs in log(sum(weights) - max(weights)) iterations, and for each iteration, we check if the current capacity can ship all packages in O(n) time.
// Space Complexity: O(1), as we are using a constant amount of extra space regardless

// Approach: 1. Use binary search to find the minimum ship capacity. The search space is between the maximum weight of a single package and the sum of all package weights.
// 2. For each mid value (potential ship capacity), check if it is possible to ship all packages within the given number of days using that capacity.
// 3. If it is possible, try to find a smaller capacity (high = mid). If it is not possible, increase the capacity (low = mid + 1).
// 4. Continue the binary search until low equals high, and return the low value, which will be the minimum ship capacity that satisfies the condition.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canShip(const vector<int>& weights, int days, int capacity){
        int currentLoad = 0;
        int requiredDay = 1;

        for(int i = 0; i < weights.size(); i++){
            if(currentLoad + weights[i] > capacity){
                requiredDay++;
                currentLoad = weights[i];
            }
            else{
                currentLoad += weights[i];
            }
        }
        return requiredDay <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canShip(weights, days, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }
        return low;
    }
};