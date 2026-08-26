// Problem: Given an array of weights representing the weights of packages and an integer days representing the number of days to ship all packages, find the minimum ship capacity required to ship all packages within the given number of days. The packages must be shipped in the order they are given.
// Time Complexity: O(n log(sum(weights) - max(weights))), where n is the number of packages. The binary search runs in log(sum(weights) - max(weights)) iterations, and for each iteration, we check if the current capacity can ship all packages in O(n) time.
// Space Complexity: O(1), as we are using a constant amount of extra space regardless

// Approach: 1. Use binary search to find the minimum ship capacity. The search space is between the maximum weight of a single package and the sum of all package weights.
// 2. For each mid value (potential ship capacity), check if it is possible to ship all packages within the given number of days using that capacity.
// 3. If it is possible, try to find a smaller capacity (high = mid). If it is not possible, increase the capacity (low = mid + 1).
// 4. Continue the binary search until low equals high, and return the low value, which will be the minimum ship capacity that satisfies the condition.

#include <iostream>   // Allows input/output operations such as cout and cin.
#include <vector>     // Allows us to use the vector container.
#include <algorithm>  // Provides functions such as max_element().
#include <numeric>    // Provides the accumulate() function.

using namespace std;

class Solution {
public:

    // This function checks whether we can ship all packages within the given number of days using the given ship capacity.
    bool canShip(const vector<int>& weights, int days, int capacity) {

        // currentLoad stores the total weight currently loaded on the ship for the current day.
        int currentLoad = 0;

        // requiredDays stores how many days are actually needed to ship all the packages with the given capacity.
        // We start with 1 because initially we are shipping on Day 1.
        int requiredDays = 1;

        // Traverse through every package in the given order.
        for (int i = 0; i < weights.size(); ++i) {

            // Check if adding the current package would exceed the ship's maximum capacity.
            if (currentLoad + weights[i] > capacity) {

                // If the current package cannot fit today, we need to use one more day.
                requiredDays++;

                // Start a new day's shipment. The current package will be loaded into this new day.
                currentLoad = weights[i];
            }
            else {

                // If the package fits within the capacity, add its weight to the current day's load.
                currentLoad += weights[i];
            }
        }

        // If all packages can be shipped in 'days' or fewer days, this capacity is valid.
        return requiredDays <= days;
    }


    // This function finds the minimum ship capacity required to ship all packages within the given number of days.
    int leastWeightCapacity(vector<int>& weights, int days) {

        // The minimum possible capacity must be at least equal to the weight of the heaviest package.

        // Example:
        // weights = [3, 2, 10, 4]
        // The ship capacity cannot be less than 10 because the package weighing 10 must fit on the ship.
        int low = *max_element(weights.begin(), weights.end());

        // The maximum possible capacity is the sum of all package weights.
        // With this capacity, we can ship every package in just one day.
        int high = accumulate(weights.begin(), weights.end(), 0);


        // We perform binary search on the possible capacity range.
        // We want to find the smallest capacity that can successfully ship all packages within the required number of days.
        while (low < high) {

            // Calculate the middle capacity.
            // This formula avoids potential integer overflow compared to:
            // (low + high) / 2
            int mid = low + (high - low) / 2;


            // Check whether 'mid' capacity is sufficient.
            if (canShip(weights, days, mid)) {

                // If this capacity works, it might not be the minimum.
                // Therefore, search for a smaller valid capacity.
                high = mid;

            } else {

                // If this capacity does not work, it is too small.
                // Therefore, we must search in the larger capacities.
                low = mid + 1;
            }
        }


        // When low == high, we have found the smallest capacity that allows all packages to be shipped within 'days' days.
        return low;
    }
};