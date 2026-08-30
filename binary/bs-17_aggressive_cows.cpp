// Problem: Aggressive Cows 
// Time Complexity: O(nlogn) + O(nlogm) where n is the number of stalls and m is the distance between the first and last stall
// Space Complexity: O(1)

// Approach: 1. Sort the stalls in ascending order.
// 2. Initialize low and high pointers to the minimum and maximum possible distances between cows.
// 3. Use binary search to find the maximum minimum distance that can be achieved by placing the cows
// 4. In each iteration, calculate the mid distance and check if it is possible to place the cows with that distance using the canWePlace function.
// 5. If it is possible, move the low pointer to mid + 1 to check for a larger distance. If it is not possible, move the high pointer to mid - 1 to check for a smaller distance.
// 6. After the loop, the maximum minimum distance will be stored in the high pointer, which is returned as the result.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

    bool canWePlace(vector<int> &stalls, int dist, int cows){
        int cntCows = 1, last = stalls[0];
        for(int i = 0; i < stalls.size(); i++){
            if(stalls[i] - last >= dist){
                cntCows++;
                last = stalls[i];
            }
            if(cntCows >= cows) return true;
        }

        return false;

    }
    
    int aggressiveCows(vector<int> & stalls, int cows){
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low = 1, high = stalls[n-1] - stalls[0];

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canWePlace(stalls, mid, cows) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }

        }
        return high;
    }
};

int main(){
    Solution s;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    cout << s.aggressiveCows(stalls, cows) << endl;
}