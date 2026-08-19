// Problem: Find the floor of a target value in a sorted array using binary search.
// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of space.

// Approach:
// 1. Initialize two pointers, left and right, to the start and end of the array, respectively.
// 2. Use a while loop to perform binary search until left is less than or equal to right.
// 3. Calculate the mid index and compare the mid value with the target.
// 4. If the mid value is equal to the target, return the mid index as the floor.
// 5. If the mid value is less than the target, update the floor index to mid and move the left pointer to mid + 1 to search in the right half.
// 6. If the mid value is greater than the target, move the right pointer to mid - 1 to search in the left half.
// 7. If the loop ends without finding an exact match, return the floor index, which will be -1 if no floor exists.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int findFloor(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int floorIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Exact match found
            } else if (nums[mid] < target) {
                floorIndex = mid; // Potential floor found
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }

        return floorIndex; // Return the index of the floor element or -1 if not found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 4, 6, 8, 10};
    int target = 5;

    int floorIndex = solution.findFloor(nums, target);
    if (floorIndex != -1) {
        cout << "Floor of " << target << " is at index: " << floorIndex << ", value: " << nums[floorIndex] << endl;
    } else {
        cout << "No floor found for " << target << endl;
    }

    return 0;
}