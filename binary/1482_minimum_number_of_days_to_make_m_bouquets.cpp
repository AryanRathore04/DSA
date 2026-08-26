// Leetcode 1482. Minimum Number of Days to Make m Bouquets
// Time Complexity: O(n log(max-min)), where n is the size of bloomDay array, max is the maximum value in bloomDay and min is the minimum value in bloomDay.
// Space Complexity: O(1)

// Approach: 1. Create a function possible() which will check if we can make m bouquets with k flowers in mid days or not.
// 2. If we can make m bouquets in mid days then we will try to find the minimum days by reducing the high value to mid-1.
// 3. If we can't make m bouquets in mid days then we will try to find the minimum days by increasing the low value to mid+1.
// 4. Finally, we will return the low value which will be the minimum days to make m bouquets.

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int mid) {
        int count = 0;
        int noOfBouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            // Flower has bloomed by 'mid' day
            if (bloomDay[i] <= mid) {
                count++;
            }
            else {
                // Make bouquets from consecutive bloomed flowers
                noOfBouquets += count / k;

                // Adjacency breaks here
                count = 0;
            }
        }

        // Handle consecutive flowers left at the end
        noOfBouquets += count / k;

        // We need at least m bouquets, not k bouquets
        return noOfBouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        // Use long long because m * k can overflow int
        long long val = 1LL * m * k;

        // Impossible to make enough bouquets
        if (bloomDay.size() < val) {
            return -1;
        }

        int maxi = INT_MIN;
        int mini = INT_MAX;

        // Find the binary search range
        for (int i = 0; i < bloomDay.size(); i++) {
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;

        // Find the first day when making m bouquets becomes possible
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, m, k, mid)) {
                // Possible on this day, search for an earlier day
                high = mid - 1;
            }
            else {
                // Not possible yet, need more days
                low = mid + 1;
            }
        }

        return low;
    }
};