// Leetcode 1732. Find the Highest Altitude
// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach:
// 1. Initialize two variables: currentAltitude to keep track of the current altitude and highestAltitude to keep track of the highest altitude reached.
// 2. Iterate through the gain array, updating  currentAltitude by adding the current gain value.
// 3. After updating currentAltitude, check if it is greater than highestAltitude. If it is, update highestAltitude.
// 4. After iterating through the entire gain array, return highestAltitude as the result.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int highestAltitude = 0;
        int n = gain.size();
        
        for(int i = 0; i < n; i++){
            currentAltitude += gain[i];
            highestAltitude = max(currentAltitude, highestAltitude);
        }
        return highestAltitude;

    }
};