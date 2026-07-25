// Leetcode Problem: 118. Pascal's Triangle
// Time Complexity: O(N^2) - Nested loops to generate N rows
// Space Complexity: O(N^2) - Storing the entire triangle in a 2D vector

// Approach: We generate Pascal's Triangle row by row. Each element in a row is calculated using the formula for combinations (nCr). We start with the first element as 1 and iteratively compute the next elements using the relationship between consecutive elements in the row. This avoids calculating factorials directly and reduces the risk of overflow.

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

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mainAns;

        for(int row = 1; row <= numRows; row++){
            mainAns.push_back(generateRow(row));
        }

        return mainAns;
    }
};