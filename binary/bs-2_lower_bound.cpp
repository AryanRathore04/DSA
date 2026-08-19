// Problem: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. You must write an algorithm with O(log n) runtime complexity.

// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: The binary search algorithm works by maintaining two pointers, low and high, which represent the current search space. In each iteration, we calculate the middle index and compare the middle element with the target value. If the middle element is greater than or equal to the target, we update the answer to mid and move the high pointer to mid - 1. Otherwise, we move the low pointer to mid + 1. This process continues until the search space is exhausted. Finally, we return the answer which represents the index where the target would be inserted in order.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int lowerBound(vector<int>& nums, int n, int x){
        int low = 0;
        int high = nums.size() - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int result = solution.lowerBound(nums, nums.size(), target);
    cout << "The lower bound index of " << target << " is: " << result << endl;
    return 0;
}