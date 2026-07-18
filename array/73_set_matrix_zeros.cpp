// Leetcode Problem 73: Set Matrix Zeros
// Time Complexity: O(n*m)
// Space Complexity: O(1)

// Approach:
// 1. We will use the first row and first column of the matrix to mark which rows and columns should be set to zero.
// 2. We will iterate through the matrix and if we find a zero, we will mark the corresponding row and column in the first row and first column
// 3. After marking, we will iterate through the matrix again and set the elements to zero based on the marks in the first row and first column.
// 4. Finally, we will check if the first row and first column need to be set to zero based on the marks.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    // mark the row
                    matrix[i][0] = 0;
                    // mark the column
                    if(j != 0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }
        // update only the inner matrix 
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][0] == 0|| matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // update the first row
        if(matrix[0][0] == 0){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }

        //update the first column
        if(col0 == 0){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }

    }
};