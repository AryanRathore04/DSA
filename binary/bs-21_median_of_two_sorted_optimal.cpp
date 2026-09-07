// Problem: Median of Two Sorted Arrays Optimal Solution
// Time Complexity: O(log(min(n1, n2)))
// Space Complexity: O(1)

// Approach: 1. Initialize n1 and n2 as the sizes of the two arrays a and b respectively.
// 2. If n1 is greater than n2, swap the arrays to ensure that a is the smaller array.
// 3. Use binary search on the smaller array a to find the correct partition point.
// 4. Calculate the left and right elements of both arrays based on the partition
// 5. Check if the partition is valid by comparing the left and right elements.
// 6. If the partition is valid, calculate the median based on the total number of elements (even or odd).
// 7. If the partition is not valid, adjust the binary search range accordingly.
// 8. Return the calculated median.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    double median(vector<int>& a, vector<int>& b){
        int n1 = a.size();
        int n2 = b.size();
        int n = n1 + n2;

        if(n1 > n2) return median(b, a); // Ensure that a is the smaller array

        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2; // Total elements in the left partition

        while(low <= high){
            int mid1 = (low + high) >> 1; // Partition index for a
            int mid2 = left - mid1; // Partition index for b

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < n1) r1 = a[mid1]; // Right element of a
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1]; // Left element of a
            if(mid2 < n2) r2 = b[mid2]; // Right element of b
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1]; // Left element of b

            // Check if we have found the correct partition
            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 1){
                    return max(l1, l2); 
                }
                return (double)(max(l1, l2) + min(r1, r2)) / 2; // Average of the two middle elements
            }
            else if(l1 > r2){
                high = mid1 - 1; // Move left in a
            }
            else{
                low = mid1 + 1; // Move right in a
            }

        }
        return 0.0; // This should never be reached
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout << "Median: " << sol.median(a, b) << endl; // Output: Median: 2

    vector<int> c = {1, 2};
    vector<int> d = {3, 4};
    cout << "Median: " << sol.median(c, d) << endl; // Output: Median: 2.5

    return 0;
}