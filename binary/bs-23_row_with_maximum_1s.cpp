// Problem: Find the row with the maximum number of 1s in a binary matrix where each row is sorted in non-decreasing order.

// Time Complexity: O(n log m), where n is the number of rows and m is the number of columns.
// Space Complexity: O(1)

// Approach: 1. Initialize cnt_max to 0 and row_index to -1 to keep track of the maximum count of 1s and the corresponding row index.
// 2. Iterate through each row of the matrix:
//    a. For each row, use the lowerBound function to find the index of the first occurrence of 1. The number of 1s in the row can be calculated as m - index_of_first_1.
//    b. If the count of 1s in the current row is greater than cnt_max, update cnt_max and row_index with the current row's count and index.
// 3. After checking all rows, return row_index as the row with the maximum number of 1s. If no 1s are found in any row, row_index will remain -1, indicating that there are no rows with 1s.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int lowerBound(vector<int>& arr, int n, int target) {
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(arr[mid] < target){
                low = mid + 1; // Move right if mid element is less than target
            }
            else{
                high = mid - 1; // Move left if mid element is greater than or equal to target
            }
        }
        return low; // Return the index of the first occurrence of target or the insertion point
    }

    int rowWithMax1s(vector<vector<int>>& mat, int n, int m) {
        int cnt_max = 0; // Maximum count of 1s found in any row
        int row_index = -1; // Index of the row with the maximum count of 1s

        for(int i = 0; i < n; i++){
            int cnt_ones = m - lowerBound(mat[i], m, 1);
            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                row_index = i;
            }
        }
        return row_index;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1}
    };
    int n = mat.size();
    int m = mat[0].size();
    int result = sol.rowWithMax1s(mat, n, m);
    cout << "The row with the maximum number of 1s is: " << result << endl;
    return 0;
}