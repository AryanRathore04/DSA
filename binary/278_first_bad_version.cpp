// Leetcode Problem: 278. First Bad Version
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: The binary search algorithm is used to find the first bad version in a sequence of versions. The algorithm maintains two pointers, low and high, which represent the current search space. In each iteration, the middle index is calculated and checked using the isBadVersion API. If the middle version is bad, the search continues in the left half of the array (including mid), otherwise, it continues in the right half (excluding mid). This process continues until the search space is exhausted. Finally, the first bad version is returned.

#include <iostream>
#include <vector>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    bool isBadVersion(int version) {
        // This function is a placeholder for the actual API call.
        // In practice, this would check if the given version is bad.
        return false; // Replace with actual implementation
    }

    int firstBadVersion(int n) {
        int low = 1;
        int high = n;

        while(low < high){
        int mid = low + (high - low) / 2;

            if(isBadVersion(mid) == true){
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};