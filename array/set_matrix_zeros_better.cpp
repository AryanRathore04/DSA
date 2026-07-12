// Problem: Set matrix Zeros Better Solution
// Time Complexity: O(2 * n * m)
// Space Complexity: O(n + m)

// Approach: 1. We will create two arrays, one for rows and one for columns, to keep track of which rows and columns need to be set to zero.
// 2. We will iterate through the matrix and mark the rows and columns that need to be set to zero.
// 3. Finally, we will iterate through the matrix again and set the elements to zero if their row or column is marked.
// 4. We will return the modified matrix.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }

        return matrix;
    }
};


int main(){
    Solution solution;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,0,6},
        {7,8,9}
    };
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> result = solution.zeroMatrix(matrix, n, m); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}