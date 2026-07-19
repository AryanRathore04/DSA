// Rotate a matrix by 90 degrees clockwise
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// Logic: To rotate a matrix by 90 degrees clockwise, we can create a new matrix and fill it with the elements of the original matrix in the rotated positions. The element at position (i, j) in the original matrix will be moved to position (j, n - 1 - i) in the new matrix, where n is the number of rows in the original matrix. After filling the new matrix, we can assign it back to the original matrix.

#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans(n, vector<int>(m));
    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(matrix);

    // Print the rotated matrix
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}