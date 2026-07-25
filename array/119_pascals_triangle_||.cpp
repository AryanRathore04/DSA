// Leetcode Problem: 119. Pascal's Triangle II
// Time Complexity: O(rowIndex) - Loop runs rowIndex times
// Space Complexity: O(rowIndex) - Storing the elements of the row in a vector

// Approach: We calculate the elements of the given row in Pascal's Triangle using the formula for combinations (nCr). We start with the first element as 1 and iteratively compute the next elements using the relationship between consecutive elements in the row. This avoids calculating factorials directly and reduces the risk of overflow.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for(int col = 1; col < rowIndex + 1; col++){
            ans = ans * (rowIndex - col + 1);
            ans = ans / col;

            ansRow.push_back(ans);
        }

        return ansRow;
    }
};