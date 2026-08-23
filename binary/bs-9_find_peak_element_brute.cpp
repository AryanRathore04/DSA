// Problem: Find Peak Element Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach: 1. Iterate through the array and check if the current element is greater than its neighbors.
// 2. If it is, return the index of the current element as the peak element.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if((i == 0 || nums[i-1] < nums[i]) && (i == nums.size()-1 || nums[i] > nums[i+1])){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    int peakIndex = solution.findPeakElement(nums);
    cout << "Peak element index: " << peakIndex << endl; // Output: Peak element index: 2
    return 0;
}