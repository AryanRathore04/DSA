// Problem: 240. Search a 2D Matrix II
// Time Complexity: O(n + m), where n is the number of rows and m is the number of columns.
// Space Complexity: O(1)

// Approach: 1. Start from the top-right corner of the matrix.
// 2. Compare the current element with the target:
//    a. If the current element is equal to the target, return true.
//    b. If the current element is less than the target, move down to the next row.
//    c. If the current element is greater than the target, move left to the previous column.
// 3. Repeat the process until the target is found or the indices go out of bounds. If the target is not found, return false to indicate that the element is not present in the matrix.

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m - 1;

        while(row < n && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                row++;
            }
            else{
                col--;
            }
        }

        return false;
    }
};