// Leetcode 1901. Find a Peak Element II
// Time Complexity: O(n * log(m)), where n is the number of rows and m is the number of columns.
// Space Complexity: O(1)

// Approach: 1. Use binary search on the columns of the matrix.
// 2. For each middle column, find the maximum element in that column.
// 3. Compare the maximum element with its left and right neighbors:
//    a. If the maximum element is greater than both neighbors, it is a peak element.
//    b. If the maximum element is less than the left neighbor, search in the left half of the matrix.
//    c. If the maximum element is less than the right neighbor, search in the right half of the matrix.
// 4. Repeat the process until a peak element is found or the search space is exhausted. If no peak element is found, return (-1, -1)

#include <vector>
using namespace std;

class Solution {
    public:
    int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col){
        int maxValue = -1;
        int index = -1;

        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int maxRowIndex = findMaxIndex(mat, n, m, mid);

            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : INT_MIN;

            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
                return {maxRowIndex, mid};
            }
            else if(mat[maxRowIndex][mid] > right){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};