// Problem: Find the square root of a number using brute force method Brute force method
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)

// Approach: 1. Initialize ans to 1.
// 2. Loop from 1 to x, and for each i, check if i * i is less than or equal to x. If it is, update ans to i.
// 3. If i * i is greater than x, break the loop and return ans as the square root of x.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int findsqrt(int x){
        int ans = 1;
        for(int i = 1; i <= x; i++){
            if(i * i <= x){
                ans = i;
            }
            else{
                break;
            }
        }
        return ans;
    }
};

int main(){
    Solution findSqrt;
    int x = 16;
    int result = findSqrt.findsqrt(x);
    cout << "Square root of " << x << " is: " << result << endl; // Output: Square root of 16 is: 4
    return 0;
}