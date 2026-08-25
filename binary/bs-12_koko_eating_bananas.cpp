// Problem: Koko Eating Bananas
// Time Complexity: O(n log m), where n is the number of piles and m is the maximum number of bananas in a pile
// Space Complexity: O(1)

// Approach: 1. Find the maximum number of bananas in the piles to set the upper limit for binary search.
// 2. Use binary search to find the minimum eating speed (k) that allows Koko to eat all the bananas within h hours. For each mid value (potential eating speed), calculate the total hours needed to eat all the bananas. If the total hours is less than or equal to h, we can try a smaller eating speed (move the high pointer). If the total hours is greater than h, we need to increase the eating speed (move the low pointer). Continue this process until the low pointer exceeds the high pointer. The low pointer will point to the minimum eating speed that allows Koko to finish eating all the bananas within h hours.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    public:
    // Function to find the maximum number of bananas in the piles
        int findMax(vector<int> &v){
            int maxi = INT_MIN;
            int n = v.size();
            // Loop through the vector to find the maximum value
            for(int i = 0; i < n; i++){
                maxi = max(maxi, v[i]); // Update maxi if the current element is greater
            }
            return maxi;
        }
        // Function to calculate the total hours needed to eat all bananas at a given rate
        int calculateTotalHours(vector<int> &v, int hourlyRate){
            int totalHours = 0;
            for(int i = 0; i < v.size(); i++){
                totalHours += (v[i] + hourlyRate - 1) / hourlyRate; // Ceiling division
            }
            return totalHours;
        }

        // Function to find the minimum rate to eat all bananas within h hours
        int minimumRateToEatBananas(vector<int> v, int h){
            int low = 1;
            int high = findMax(v);

            while(low <= high){
                int mid = low + (high - low) / 2;
                int totalHours = calculateTotalHours(v, mid); // Calculate total hours needed at the current rate

                if(totalHours <= h){
                    high = mid - 1; // Try to find a smaller rate
                } else {
                    low = mid + 1; // Increase the rate
                }
            }
            return low; // The minimum rate found
        }
};

int main() {
    Solution solution;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int result = solution.minimumRateToEatBananas(piles, h);
    cout << "Minimum rate to eat all bananas in " << h << " hours: " << result << endl;
    return 0;
}