// Problem: Find the kth missing positive number from a sorted array of positive integers.
// Time Complexity: O(log n) - Binary search is used to find the kth missing number.
// Space Complexity: O(1) - Constant space is used.

// Approach: 1. Initialize low and high pointers to the start and end of the array.
// 2. Use binary search to find the position where the kth missing number would fit.
// 3. Calculate the number of missing elements up to the mid index.
// 4. If the number of missing elements is less than k, move the low pointer to mid + 1.
// 5. If the number of missing elements is greater than or equal to k, move the high pointer to mid - 1.
// 6. After the loop, the kth missing number can be calculated as high + k + 1, where high is the last index checked and k is the number of missing elements we are looking for.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int missingK(vector<int> vec, int n, int k){
        int low = 0, high = n -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // Calculate the number of missing elements up to index mid
            int missing = vec[mid] - (mid + 1);
            if(missing < k){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high + k + 1;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {2, 3, 4, 7, 11};
    int k = 5;
    int result = sol.missingK(vec, vec.size(), k);
    cout << "The " << k << "th missing positive number is: " << result << endl;
    return 0;
}