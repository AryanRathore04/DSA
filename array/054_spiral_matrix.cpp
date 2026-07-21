// Leetcode 54. Spiral Matrix
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// Approach:
// 1. Initialize four pointers: left, right, top, and bottom to represent the boundaries of the matrix.
// 2. Create an empty vector ans to store the elements in spiral order.
// 3. Use a while loop that continues until the top pointer is less than or equal to the bottom pointer and the left pointer is less than or equal to the right pointer.
// 4. Inside the loop, perform the following steps:
//    a. Traverse from left to right along the top boundary and add the elements to ans. Increment the top pointer.
//    b. Traverse from top to bottom along the right boundary and add the elements to ans. Decrement the right pointer.
//    c. If the top pointer is still less than or equal to the bottom pointer, traverse from right to left along the bottom boundary and add the elements to ans. Decrement the bottom pointer.
//    d. If the left pointer is still less than or equal to the right pointer, traverse from bottom to top along the left boundary and add the elements to ans. Increment the left pointer.
// 5. After the loop ends, return the ans vector containing the elements in spiral order.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;

        vector<int> ans;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};