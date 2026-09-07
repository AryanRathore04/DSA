// Problem: Find the kth element in two sorted arrays
// Time Complexity: O(log(min(n1, n2)))
// Space Complexity: O(1)

// Approach: 1. Initialize n1 and n2 as the sizes of the two arrays a and b respectively.
// 2. If n1 is greater than n2, swap the arrays to ensure that a is the smaller array.
// 3. Set low and high pointers for binary search on the smaller array a. The low pointer is set to max(k-n2, 0) and the high pointer is set to min(k, n1).
// 4. Perform binary search while low is less than or equal to high:
//    a. Calculate mid1 as the average of low and high, which represents the partition index for array a.
//    b. Calculate mid2 as left - mid1, which represents the partition index for array b.
//    c. Initialize l1, l2, r1, and r2 to represent the left and right elements of the partitions in arrays a and b. Set l1 and l2 to INT_MIN and r1 and r2 to INT_MAX to handle edge cases where the partitions are at the boundaries of the arrays.
//    d. Update l1, l2, r1, and r2 based on the partition indices mid1 and mid2. If mid1 is less than n1, set r1 to a[mid1]. If mid1 - 1 is greater than or equal to 0, set l1 to a[mid1 - 1]. If mid2 is less than n2, set r2 to b[mid2]. If mid2 - 1 is greater than or equal to 0, set l2 to b[mid2 - 1].
//    e. Check if the partitions are valid by ensuring that l1 <= r2 and l2 <= r1. If they are valid, return the maximum of l1 and l2 as the kth element.
//    f. If l1 > r2, move the high pointer to mid1 - 1 to search in the left half of array a. Otherwise, move the low pointer to mid1 + 1 to search in the right half of array a.
// 5. If the loop ends without finding the kth element, return 0.0 as a fallback (this should never be reached if the input is valid).

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    double kthElement(vector<int>& a, vector<int>& b, int k){
        int n1 = a.size();
        int n2 = b.size();
        int n = n1 + n2;

        if(n1 > n2) return kthElement(b, a, k); // Ensure that a is the smaller array

        int low = max(k-n2, 0), high = min(k, n1);
        int left = k; // Total elements in the left partition

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
                    return max(l1, l2); 
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
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    double result = sol.kthElement(a, b, k);
    cout << "The " << k << "th element is: " << result << endl;
    return 0;
}