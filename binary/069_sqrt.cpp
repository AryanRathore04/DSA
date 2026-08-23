// Leetcode 69. Sqrt(x)
// Problem: Find the square root of a number using binary search Optimal method
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: 1. Initialize low to 1 and high to x, and ans to 0.
// 2. While low is less than or equal to high, calculate the mid index.
// 3. Calculate midSqt as mid * mid.
// 4. If midSqt is equal to x, return mid as the square root.
// 5. If midSqt is less than x, update ans to mid and set low to mid + 1 to search in the right half.
// 6. If midSqt is greater than x, set high to mid - 1 to search in the left half.
// 7. Return ans as the floor of the square root of x.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x, ans = 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long midSqt = mid * mid;

            if(midSqt == x){
                return mid;
            }
            else if(midSqt < x){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};