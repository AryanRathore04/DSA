// Problem: Count Reverse Pairs in an Array Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Approach: The brute force approach involves using two nested loops to iterate through the array and count the number of reverse pairs. A reverse pair is defined as a pair of indices (i, j) such that i < j and nums[i] > 2 * nums[j]. The outer loop iterates through each element in the array, while the inner loop checks for all subsequent elements to find valid reverse pairs. The count of such pairs is maintained and returned at the end.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int reversePairs(vector<int> &nums){
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] > 2 * nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {40, 25, 19, 12, 9, 6, 2};
    int result = solution.reversePairs(nums);
    cout << "Number of reverse pairs: " << result << endl;
    return 0;
}