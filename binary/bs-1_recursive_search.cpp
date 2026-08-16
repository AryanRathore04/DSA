// Problem: Find a target value in a sorted array using recursive binary search.
// Time Complexity: O(log n) - The binary search algorithm divides the search space in half with each recursive call, leading to logarithmic time complexity.
// Space Complexity: O(log n) - The recursive calls add to the call stack, which can take up to O(log n) space in the worst case.

// Approach: The recursive binary search algorithm works by maintaining two pointers, low and high, which represent the current search space. In each recursive call, we calculate the middle index and compare the middle element with the target value. If they are equal, we return the index. If the target is greater than the middle element, we recursively search in the right half of the array; otherwise, we search in the left half. This process continues until the target is found or the search space is exhausted.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int bs(vector<int>& nums, int low, int high, int target){
        if(low > high) return -1;

        int mid = (low + high) / 2;

        if(nums[mid] == target){
            return mid;
        }
        else if(target > nums[mid]){
            return bs(nums, mid + 1, high, target);
        }

        return bs(nums, low, high - 1, target);
    }

    int search(vector<int>& nums, int target){
        return bs(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 3;
    int result = solution.search(nums, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}