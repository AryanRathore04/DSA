// Leetcode Problem: 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Approach: We can use two nested loops to generate all possible subarrays of the given array. For each subarray, we calculate the XOR of its elements in a single pass and check if it is equal to 0. If it is, we increment the count of such triplets by (k - i), where k is the end index of the subarray and i is the start index. Finally, we return the count.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            int xr = 0;
            for(int k = i; k < n; k++){
                xr ^= arr[k];

                if(xr == 0){
                    count += (k - i);
                }
            }
        }

        return count;
    }
};