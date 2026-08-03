// Problem: Find the missing and repeating number in an array Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Approach:
// 1. Iterate through the numbers from 1 to n.
// 2. For each number, count its occurrences in the array.
// 3. If a number occurs twice, it is the repeating number.
// 4. If a number does not occur, it is the missing number.
// 5. Return the repeating and missing numbers as a vector.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> findMissingAndRepeating(vector<int> &arr, int n){
        vector<int> ans(2);

        int repeating = -1, missing = -1;

        for(int i = 1; i <= n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(arr[j] == i){
                    count++;
                }
                if(count == 2){
                    repeating = i;
                }
                else if(count == 0){
                    missing = i;
                }

                if(repeating != -1 && missing != -1){
                    break;
                }
            }
        }
        ans[0] = repeating;
        ans[1] = missing;
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution solution;
    vector<int> result = solution.findMissingAndRepeating(arr, n);

    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}