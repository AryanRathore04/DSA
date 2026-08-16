// Problem: Write a function to search for a target value in a sorted array using binary search.
// Time Complexity: O(log n) - The binary search algorithm divides the search space in half with each iteration, leading to logarithmic time complexity.
// Space Complexity: O(1) - The algorithm uses a constant amount of space for variables, regardless of the input size.

// Approach: The binary search algorithm works by maintaining two pointers, low and high, which represent the current search space. In each iteration, we calculate the middle index and compare the middle element with the target value. If they are equal, we return the index. If the target is greater than the middle element, we move the low pointer to mid + 1; otherwise, we move the high pointer to mid - 1. This process continues until the target is found or the search space is exhausted.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int search(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0; // index of the first element
        int high = n-1; // index of the last element

        while(low <= high){
            int mid = (low + high) / 2; // index of the middle element

            if(nums[mid] == target) return mid;
            else if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
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