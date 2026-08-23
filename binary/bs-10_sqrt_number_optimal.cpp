// Problem: Find the floor of the square root of a given number x using binary search Optimal method
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: 1. Initialize low to 1 and high to x, and ans to 0.
// 2. While low is less than or equal to high, calculate the mid index.
// 3. Calculate midSq as mid * mid.
// 4. If midSq is equal to x, return mid as the square root.
// 5. If midSq is less than x, update ans to mid and set low to mid + 1 to search in the right half.
// 6. If midSq is greater than x, set high to mid - 1 to search in the left half.
// 7. Return ans as the floor of the square root of x.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int floorSqrt(int x){
        int low = 1, high = x, ans = 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long midSq = mid * mid;

            if(midSq == x){
                return mid;
            }
            else if(midSq < x){
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

int main(){
    Solution findSqrt;
    int x = 16;
    int result = findSqrt.floorSqrt(x);
    cout << "Floor square root of " << x << " is: " << result << endl; // Output: Floor square root of 16 is: 4
    return 0;
}