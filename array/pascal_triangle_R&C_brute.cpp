// Pascal's Triangle - nCr (Brute Force Approach)
// Time Complexity: O(r) - Loop runs r times
// Space Complexity: O(1) - Constant space used

// Approach: We calculate nCr using the formula nCr = n! / (r! * (n - r)!). Instead of calculating factorials directly, we use a loop to compute the result iteratively, which avoids large intermediate values and reduces the risk of overflow.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int nCr(int n, int r){
        long long res = 1;
        for(int i = 0; i < r; i++){
            res *= (n - i);
            res /= (i + 1);
        }
        return (int)res;
    }
};

int main() {
    Solution sol;
    int n = 5, r = 2;
    cout << "C(" << n << ", " << r << ") = " << sol.nCr(n, r) << endl;
    return 0;
}