// Problem Statement: Given an array of size n, containing numbers from 1 to n. One number is missing and one number is repeating. Find the missing and repeating numbers in O(n) time complexity and O(1) space complexity. Optimal approach is to use mathematical formulas to find the missing and repeating numbers.

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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<int> findMissingRepeatingNumbers(vector<int> a){
        long long n = a.size();

        // S - sn = x - y
        long long SN = n * (n + 1) / 2; // Sum of first n natural numbers

        // S2 - sn2 = x^2 - y^2
        long long S2N = (n * (n+1) * (2*n+1)) / 6; // Sum of squares of first n natural numbers

        long long S = 0, S2 = 0;

        for(int i = 0; i < n; i++){
            S += a[i];
            S2 += (long long)a[i] * (long long)a[i];
        }

        long long val1 = S - SN; // x - y
        long long val2 = S2- S2N; // x^2 - y^2
        val2 = val2 / val1; // x + y

        long long x = (val1 + val2) / 2; // x = (x - y + x + y) / 2
        long long y = x - val1; // y = x - (x - y) = y

        return {(int)x, (int)y};
    }
};

int main(){
    Solution s;
    vector<int> a = {3, 1, 3};
    vector<int> result = s.findMissingRepeatingNumbers(a);
    cout << "Repeating number: " << result[0] << ", Missing number: " << result[1] << endl;
    return 0;
}

