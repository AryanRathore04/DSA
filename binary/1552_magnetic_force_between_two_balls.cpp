// Leetcode 1552. Magnetic Force Between Two Balls
// Time Complexity: O(n log n)
// Space Complexity: O(1)

// Approach: 1. Sort the position array in ascending order.
// 2. Initialize low and high pointers to the minimum and maximum possible distances between balls.
// 3. Use binary search to find the maximum minimum distance that can be achieved by placing the balls
// 4. In each iteration, calculate the mid distance and check if it is possible to place the balls with that distance using the canWePlace function.
// 5. If it is possible, move the low pointer to mid + 1 to check for a larger distance. If it is not possible, move the high pointer to mid - 1 to check for a smaller distance.
// 6. After the loop, the maximum minimum distance will be stored in the high pointer, which is returned as the result.

#include <vector>
using namespace std;

class Solution {
public:
    int canWePlace(vector<int>& position, int dist, int m) {
        int cntBalls = 1;
        int last = position[0];

        for (int i = 0; i < position.size(); i++) {
            if (position[i] - last >= dist) {
                cntBalls++;
                last = position[i];
            }
            if(cntBalls >= m) return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1, high = position[n - 1] - position[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if(canWePlace(position, mid, m) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return high;
    }
};