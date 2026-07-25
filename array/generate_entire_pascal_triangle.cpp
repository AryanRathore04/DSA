#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for(int col = 1; col < row; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }

        return ansRow;
    }

    vector<vector<int>> pascalTriangle(int N){
        vector<vector<int>> ans;

        for(int row = 1; row <= N; row++){
            ans.push_back(generateRow(row));
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int N = 5; // Example number of rows
    vector<vector<int>> triangle = sol.pascalTriangle(N);

    cout << "Pascal's Triangle with " << N << " rows:" << endl;
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}