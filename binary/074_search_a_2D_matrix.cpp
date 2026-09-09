// Leetcode 74: Search a 2D Matrix
// Time Complexity: O(log(n * m)), where n is the number of rows and m is the number of columns.
// Space Complexity: O(1)

// Approach: 1. Treat the 2D matrix as a 1D sorted array by calculating the mid index and mapping it to the corresponding row and column in the matrix.
// 2. Use binary search to find the target value:
//    a. Calculate the mid index and map it to the corresponding row and column in the matrix.
//    b. If the mid element is equal to the target, return true.
//    c. If the mid element is less than the target, move the low pointer to mid + 1.
//    d. If the mid element is greater than the target, move the high pointer to mid - 1.
// 3. If the target is not found after the loop, return false.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = m * n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};

