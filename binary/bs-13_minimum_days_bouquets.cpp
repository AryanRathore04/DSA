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
            if(bloomDay[i] <= mid){
                cnt++;
            } else {
                noOfBouquets += (cnt / r);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt / r);
        return noOfBouquets >= b;
    }

    int roseGarden(vector<int> bloomDay, int r, int b){
        long long val = r * 1LL * b * 1LL;
        if(bloomDay.size() < val) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(possible(bloomDay, r, b, mid)){
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