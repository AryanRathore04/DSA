// Leetcode 59. Spiral Matrix II
// Time Complexity: O(n*n)
// Space Complexity: O(n*n)

// Approach:
// 1. Initialize four pointers: left, right, top, and bottom to represent the boundaries of the matrix.
// 2. Create an empty n x n matrix to store the elements in spiral order.
// 3. Initialize a variable num to 1, which will be used to fill the matrix.
// 4. Use a while loop that continues until the top pointer is less than or equal to the bottom pointer and the left pointer is less than or equal to the right pointer.
// 5. Inside the loop, perform the following steps:
//    a. Traverse from left to right along the top boundary and fill the matrix with num. Increment num and the top pointer.
//    b. Traverse from top to bottom along the right boundary and fill the matrix with num. Increment num and decrement the right pointer.
//    c. If the top pointer is still less than or equal to the bottom pointer, traverse from right to left along the bottom boundary and fill the matrix with num. Increment num and decrement the bottom pointer.
//    d. If the left pointer is still less than or equal to the right pointer, traverse from bottom to top along the left boundary and fill the matrix with num. Increment num and increment the left pointer.
// 6. After the loop ends, return the matrix containing the elements in spiral order.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> matrix(n, vector<int>(n));

        int num = 1;

        int p = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = p - 1;
        int top = 0, bottom = n - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num;
                num++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num;
                num++;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
        }

        return matrix;
    }
};