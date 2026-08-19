// Problem: Find the first and last occurrences of a target value in a sorted array using binary search.
// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of space.

// Approach:
// 1. Implement two separate functions, firstOccure and lastOccure, to find the first and last occurrences of the target value, respectively.
// 2. In each function, initialize two pointers, low and high, to the start and end of the array, respectively.
// 3. Use a while loop to perform binary search until low is less than or equal to high.
// 4. Calculate the mid index and compare the mid value with the target.
// 5. If the mid value is equal to the target, store the index as a potential answer and continue searching in the left half for firstOccure or in the right half for lastOccure.
// 6. If the mid value is less than the target, move the low pointer to mid + 1; otherwise, move the high pointer to mid - 1.
// 7. If the loop ends without finding the target, return -1 to indicate that the target is not present in the array.
//  8. Finally, return the indices of the first and last occurrences as a vector from the searchRange function.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstOccure(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1; 

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    int lastOccure(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1; 

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccure(nums, target);
        int last = lastOccure(nums, target);

        return {first, last};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);
    cout << "First occurrence of " << target << " is at index: " << result[0] << endl;
    cout << "Last occurrence of " << target << " is at index: " << result[1] << endl;

    return 0;
}