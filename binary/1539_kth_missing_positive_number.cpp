// Leetcode 1539. Kth Missing Positive Number
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: 1. Initialize low and high pointers to the start and end of the array.
// 2. Use binary search to find the position where the kth missing number would fit.
// 3. Calculate the number of missing elements up to the mid index.
// 4. If the number of missing elements is less than k, move the low pointer to mid + 1.
// 5. If the number of missing elements is greater than or equal to k, move the high pointer to mid - 1.
// 6. After the loop, the kth missing number can be calculated as high + k + 1, where high is the last index checked and k is the number of missing elements we are looking for.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return k + high + 1;
    }
};