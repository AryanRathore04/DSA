// Problem: Painter Partition Problem
// Time Complexity: O(n log(sum of boards)), where n is the number of boards
// Space Complexity: O(1)

// Approach: 1. Initialize low as the maximum length of the boards and high as the sum of all board lengths.
// 2. Use binary search to find the minimum maximum distance that can be achieved by partitioning the boards among k painters.
// 3. For each mid value, check if it's possible to partition the boards such that no painter paints more than mid length of boards using the isPossible function.
// 4. If it's possible, update high to mid, otherwise update low to mid + 1.
// 5. Continue the binary search until low is equal to high, which will be the answer.  

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
    bool isPossible(vector<int>& boards, int k, int maxDistance) {
        int painters = 1;
        int currentSum = 0;

        for(int i = 0; i < boards.size(); i++) {
            if(currentSum + boards[i] > maxDistance) {
                painters++;
                currentSum = boards[i];
                if(painters > k) {
                    return false;
                }
            } else {
                currentSum += boards[i];
            }
        }
        return true;
    }

    public:
    int findLargestMinDistance(vector<int>& boards, int k){
        int m = boards.size();
        if(m < k) return -1; // Not enough boards for the painters

        int low = *max_element(boards.begin(), boards.end());
        int high = accumulate(boards.begin(), boards.end(), 0);

        while(low < high){
            int mid = low + (high - low) / 2;
            // Check if it's possible to partition the boards with the given maximum distance
            if(isPossible(boards, k, mid)){
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution solution;
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int result = solution.findLargestMinDistance(boards, k);
    cout << "The largest minimum distance is: " << result << endl;
    return 0;
}
