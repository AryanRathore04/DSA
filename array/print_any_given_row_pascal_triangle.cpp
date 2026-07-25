// Print any given row of Pascal's Triangle
// Time Complexity: O(rowIndex) - Loop runs rowIndex times
// Space Complexity: O(1) - Constant space used

// Approach: We calculate the elements of the given row in Pascal's Triangle using the formula for combinations (nCr). We start with the first element as 1 and iteratively compute the next elements using the relationship between consecutive elements in the row. This avoids calculating factorials directly and reduces the risk of overflow.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void printRow(int rowIndex){
        int ans = 1;
        int n = rowIndex + 1; // Since rowIndex is 0-based, we add 1 to get the number of elements in that row
        cout << ans << " "; // Print the first element of the row

        for(int i = 1; i < n; i++){
            ans = ans * (n - i); // Calculate the next element in the row using the formula for nCr
            ans = ans / i; // Divide by i to get the next element
            cout << ans << " "; // Print the current element of the row
        }
    }
};

int main() {
    Solution sol;
    int rowIndex = 4; // Example row index
    cout << "Row " << rowIndex << " of Pascal's Triangle: ";
    sol.printRow(rowIndex);
    cout << endl;
    return 0;
}