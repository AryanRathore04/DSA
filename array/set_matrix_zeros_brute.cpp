#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void markRow(int i, int m, vector<vector<int>>& matrix) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void markCol(int j, int n, vector<vector<int>>& matrix) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(matrix[i][j] == 0){

                    markRow(i, m, matrix);

                    markCol(j, n, matrix);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }

            }
        }
    }
};

int main(){

    Solution solution;

    vector<vector<int>> matrix = {

        {1,2,3},
        {4,0,6},
        {7,8,9}

    };

    solution.setZeroes(matrix);

    for(int i=0;i<matrix.size();i++){

        for(int j=0;j<matrix[0].size();j++){

            cout<<matrix[i][j]<<" ";

        }

        cout<<endl;

    }

}