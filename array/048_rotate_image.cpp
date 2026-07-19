// Leetcode Problem: 48. Rotate Image
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Approach:
// 1. First, we will transpose the matrix by swapping the elements at position (i, j) with the elements at position (j, i) for all i < j. This will convert the rows of the matrix into columns and vice versa.
// 2. After transposing, we will reverse each row of the matrix to get the final rotated matrix.   
// 3. This approach works because transposing the matrix changes the rows into columns, and reversing each row gives us the desired 90-degree clockwise rotation.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};