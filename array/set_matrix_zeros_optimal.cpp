#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
        // vector<int> col(m, 0); -> matrix[0][..]
        // vector<int> row(n, 0); -> matrix[..][0]
        int col0 = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    // mark the i-th row
                    matrix[i][0] = 0;
                    // mark the j-th col
                    if(j != 0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               if(matrix[i][j] == 0){
                // Check for the col & row
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
               }
            }
        }

        if(matrix[0][0] == 0){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }

        return matrix;
    }
};


int main(){
    Solution solution;
    vector<vector<int>> matrix = {
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1}
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