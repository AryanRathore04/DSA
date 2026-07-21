// Leetcode 867. Transpose Matrix
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// Approach:
// 1. Get the number of rows (n) and columns (m) of the input matrix.
// 2. Create a new matrix ans of size m x n to store the transposed values.
// 3. Iterate through each element of the input matrix using two nested loops.
// 4. For each element at position (i, j) in the input matrix, assign its value to the position (j, i) in the ans matrix.
// 5. After filling the ans matrix, return it as the result.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans(m ,vector<int> (n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};