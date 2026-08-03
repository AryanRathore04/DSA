// Leetcode 645. Set Mismatch
// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach:
// 1. Calculate the sum of first n natural numbers (SN) and the sum of squares of first n natural numbers (S2N).
// 2. Calculate the sum (S) and sum of squares (S2) of the given array.
// 3. Use the equations
//    S - SN = x - y (where x is the repeating number and y is the missing number)
//    S2 - S2N = x^2 - y^2
// 4. From the above equations, we can derive:
//    x + y = (S2 - S2N) / (S - SN)
// 5. Now we have two equations:
//    x - y = S - SN
//    x + y = (S2 - S2N) / (S - SN)
// 6. Solve these two equations to find x and y.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();

        long long SN = n * (n+1) / 2; 

        long long S2N = (n * (n+1) * (2*n+1)) / 6;

        long long S = 0, S2 = 0;

        for(int i = 0; i < n; i++){
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        long long val1 = S - SN;
        long long val2 = S2 - S2N;
        val2 = val2 / val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};