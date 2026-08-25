// Leetcode 875. Koko Eating Bananas
// Time Complexity: O(n log m), where n is the number of piles and m is the maximum number of bananas in a pile
// Space Complexity: O(1)

// Approach: 1. Find the maximum number of bananas in the piles to set the upper limit for binary search.
// 2. Use binary search to find the minimum eating speed (k) that allows Koko to eat all the bananas within h hours. For each mid value (potential eating speed), calculate the total hours needed to eat all the bananas. If the total hours is less than or equal to h, we can try a smaller eating speed (move the high pointer). If the total hours is greater than h, we need to increase the eating speed (move the low pointer). Continue this process until the low pointer exceeds the high pointer. The low pointer will point to the minimum eating speed that allows Koko to finish eating all the bananas within h hours.

#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        int n = piles.size();

        for(int i = 0; i < n; i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>& piles, int hourlyRate){
        long long totalHours = 0;
        for(int i = 0; i < piles.size(); i++){
            totalHours += ceil((double)piles[i] / (double)hourlyRate);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalHours = calculateTotalHours(piles, mid);

            if(totalHours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};