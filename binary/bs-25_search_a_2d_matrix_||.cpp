// Problem: Search a 2D Matrix II
// Time Complexity: O(n + m), where n is the number of rows and m is the number of columns.
// Space Complexity: O(1)

// Approach: 1. Start from the top-right corner of the matrix.
// 2. Compare the current element with the target:
//    a. If the current element is equal to the target, return its position.
//    b. If the current element is less than the target, move down to the next row.
//    c. If the current element is greater than the target, move left to the previous column.
// 3. Repeat the process until the target is found or the indices go out of bounds. If the target is not found, return (-1, -1) to indicate that the element is not present in the matrix.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    pair<int, int> searchElement(vector<vector<int>> &mat, int target){
        int n = mat.size();
        int m = mat[0].size();

        int row = 0, col = m - 1;

        while(row < n && col >= 0){
            if(mat[row][col] == target){
                return {row, col};
            }
            else if(mat[row][col] < target){
                row++;
            }
            else{
                col--;
            }
        }
        return {-1, -1};
    }
};

int main(){
    Solution sol;
    vector<vector<int>> mat = {{1, 4, 7, 11, 15},
                               {2, 5, 8, 12, 19},
                               {3, 6, 9, 16, 22},
                               {10, 13, 14, 17, 24},
                               {18, 21, 23, 26, 30}};
    int target = 5;

    pair<int, int> result = sol.searchElement(mat, target);
    if(result.first != -1 && result.second != -1){
        cout << "Element found in the matrix at position (" << result.first << ", " << result.second << ")." << endl;
    }
    else{
        cout << "Element not found in the matrix." << endl;
    }

    return 0;
}