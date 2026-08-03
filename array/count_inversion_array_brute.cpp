// Problem: Count Inversions in an Array (Brute Force Approach)
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Approach:
// 1. Initialize a count variable to 0.
// 2. Use two nested loops to iterate through the array.
// 3. For each pair of elements (arr[i], arr[j]) where i < j, check if arr[i] > arr[j].
// 4. If the condition is true, increment the count variable.
// 5. Return the count variable as the number of inversions in the array.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int countInversions(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        for(int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                if(arr[i] > arr[j]){
                    count ++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {2, 4, 1, 3, 5};
    int inversions = solution.countInversions(arr);
    cout << "Number of inversions: " << inversions << endl; // Output: Number of inversions: 3
    return 0;
}