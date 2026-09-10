// Problem: Find the median of a row-wise sorted matrix
// Time Complexity: O(n * log(max - min) * log(m)), where n is the number of rows, m is the number of columns, and max and min are the maximum and minimum elements in the matrix.
// Space Complexity: O(1)

// Approach: We can use binary search to find the median of a row-wise sorted matrix. The idea is to find the minimum and maximum elements in the matrix, and then perform a binary search on the range of values between the minimum and maximum. For each mid value, we count how many elements in the matrix are less than or equal to mid. If this count is less than or equal to half of the total number of elements, we move our search range up; otherwise, we move it down. The point where our search converges will be the median.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    // Function to find the upper bound of a target in a sorted row
    int upperBound(vector<int> &row, int target, int m){
        int low = 0, high = m - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(row[mid] <= target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
    // Function to count the number of elements less than or equal to target in the matrix
    int countSmallEqual(vector<vector<int>> &matrix, int target, int n, int m){
        int count = 0;
        for(int i = 0; i < matrix.size(); i++){
            count += upperBound(matrix[i], target, m);
        }
        return count;
    }
    // Function to find the median of a row-wise sorted matrix
    int median(vector<vector<int>> &matrix, int m, int n){
        int low = INT_MAX, high = INT_MIN;
        n = matrix.size();
        m = matrix[0].size();

        for(int i = 0; i < n; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        int req = (n * m) / 2;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int count = countSmallEqual(matrix, mid, n, m);
            if(count <= req){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};

// Write a main function to test the Solution class
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 5, 7, 9, 11},
        {2, 3, 4, 8, 9},
        {4, 11, 14, 19, 20},
        {6, 10, 22, 99, 100},
        {7, 15, 17, 24, 28}
    };
    int m = matrix.size();
    int n = matrix[0].size();
    int result = sol.median(matrix, m, n);
    cout << "The median of the matrix is: " << result << endl;
    return 0;
}