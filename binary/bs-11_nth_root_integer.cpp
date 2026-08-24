// Problem: Find the integer Nth root of a number M using binary search.
// Time Complexity: O(log m * n) where n is the root and m is the number.
// Space Complexity: O(1)

// Approach: 1. Initialize low to 1 and high to m, and ans to 0.
// 2. While low is less than or equal to high, calculate the mid index.
// 3. Calculate midPow as mid raised to the power of n.
// 4. If midPow is equal to m, return mid as the Nth root.
// 5. If midPow is less than m, set low to mid + 1 to search in the right half.
// 6. If midPow is greater than m, set high to mid - 1 to search in the left half.
// 7. If no integer root is found, return -1.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int NthRoot(int n, int m){
        int low = 1, high = m, ans = 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long midPow = 1;

            for(int i = 0; i < n; i++){
                midPow *= mid;
                if (midPow > m) break; // To prevent overflow and unnecessary calculations
            }

            if(midPow == m){
                return mid;
            }
            else if(midPow < m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n = 3; // Example: Find the cube root
    int m = 27; // Example: The number to find the root of
    int result = sol.NthRoot(n, m);
    
    if(result != -1) {
        cout << "The " << n << "th root of " << m << " is: " << result << endl;
    } else {
        cout << m << " does not have an integer " << n << "th root." << endl;
    }

    return 0;
}