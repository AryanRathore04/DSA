// Problem: Search a 2D Matrix
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
    bool searchMatrix(vector<vector<int>>& mat, int target){
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n * m - 1; // Treat the matrix as a 1D array

        while(low <= high){
            int mid = low + (high - low) / 2; // Calculate mid index

            int row = mid / m;
            int col = mid % m;

            if(mat[row][col] == target){
                return true;
            } else if(mat[row][col] < target){
                low = mid + 1; // Move right if mid element is less than target
            } else {
                high = mid - 1; // Move left if mid element is greater than target
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    bool result = sol.searchMatrix(mat, target);
    cout << "Is the target " << target << " present in the matrix? " << (result ? "Yes" : "No") << endl;
    return 0;
}