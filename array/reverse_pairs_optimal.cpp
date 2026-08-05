// Problem: Count Reverse Pairs Optimal Approach
// Time Complexity: O(n log n)
// Space Complexity: O(n)

// Approach: We can use a modified merge sort algorithm to count the number of reverse pairs in an array. A reverse pair is defined as a pair of indices (i, j) such that i < j and nums[i] > 2 * nums[j]. The idea is to divide the array into two halves, count the reverse pairs in each half recursively, and then count the reverse pairs that span across the two halves during the merge step.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Merge the two halves while maintaining sorted order
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        // Add any remaining elements from the left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        // Add any remaining elements from the right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }
        // Copy the merged elements back to the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    // Count the number of reverse pairs between the two halves
    int countPairs(vector<int>&nums, int low, int mid, int high){
        int right = mid + 1;
        int count = 0;
        // Count the number of reverse pairs
        for(int i = low; i <= mid; i++){
            while(right <= high && nums[i] > 2LL * nums[right]){
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }

    // Recursive function to perform merge sort and count reverse pairs
    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;
        // Base case: if the subarray has one or zero elements, return the count
        if (low >= high) {
            return count;
        }
        // Find the middle index to divide the array into two halves
        int mid = low + (high - low) / 2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }
    // Function to count the number of reverse pairs in the array
    int team(vector<int> &skill, int n){
        return mergeSort(skill, 0, n - 1);
    }
};


int main() {
    Solution solution;
    vector<int> nums = {40, 25, 19, 12, 9, 6, 2};
    int result = solution.team(nums, nums.size());
    cout << "Number of reverse pairs: " << result << endl;
    return 0;
}