// Problem: Minimum Days to Make m Bouquets
// Time Complexity: O(n log(max-min)), where n is the size of bloomDay array, max is the maximum value in bloomDay and min is the minimum value in bloomDay.
// Space Complexity: O(1)

// Approach: 1. Create a function possible() which will check if we can make b bouquets with r flowers in mid days or not.
// 2. If we can make b bouquets in mid days then we will try to find the minimum days by reducing the high value to mid-1.
// 3. If we can't make b bouquets in mid days then we will try to find the minimum days by increasing the low value to mid+1.
// 4. Finally, we will return the low value which will be the minimum days to make b bouquets.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    bool possible(vector<int> &bloomDay, int r, int b, int mid){
        int cnt = 0;
        int noOfBouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            // If the bloom day of the flower is less than or equal to mid, we can use it to make a bouquet
            if(bloomDay[i] <= mid){
                cnt++;
            } else {
                // If the bloom day of the flower is greater than mid, we can't use it to make a bouquet, so we will check how many bouquets we can make with the flowers we have counted so far.
                noOfBouquets += (cnt / r);
                // Reset the count of flowers for the next bouquet
                cnt = 0;
            }
        }
        // After the loop, we need to check if there are any remaining flowers that can be used to make a bouquet
        noOfBouquets += (cnt / r);
        // Finally, we will check if the number of bouquets we can make is greater than or equal to b. If it is, then we can make b bouquets in mid days, otherwise we can't.
        return noOfBouquets >= b;
    }

    int roseGarden(vector<int> bloomDay, int r, int b){
        // Calculate the total number of flowers needed to make b bouquets with r flowers each
        long long val = r * 1LL * b * 1LL;
        // If the total number of flowers needed is greater than the number of flowers we have, then it is impossible to make b bouquets, so we will return -1.
        if(bloomDay.size() < val) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi;
        // Perform binary search to find the minimum days to make b bouquets
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(possible(bloomDay, r, b, mid)){
                // If we can make b bouquets in mid days, then we will try to find the minimum days by reducing the high value to mid-1.
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int r = 1; // number of flowers per bouquet
    int b = 3; // number of bouquets needed
    int result = sol.roseGarden(bloomDay, r, b);
    cout << "Minimum days to make " << b << " bouquets: " << result << endl; // Ans: 12
    return 0;
}