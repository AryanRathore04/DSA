// Leetcode: 315. Count of Smaller Numbers After Self
// Problem: Count of Smaller Numbers After Self Optimal Approach
// Time Complexity: O(n log n)
// Space Complexity: O(n)

// Approach: We can use a modified merge sort algorithm to count the number of smaller elements after each element in an array. The idea is to divide the array into two halves, count the smaller elements in each half recursively, and then count the smaller elements that span across the two halves during the merge step. We maintain the original indices of the elements to update the answer correctly.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Merge two sorted halves and update answer
    void merge(vector<pair<int, int>>& arr, int low, int mid, int high,
               vector<int>& ans) {

        vector<pair<int, int>> temp;

        int left = low;
        int right = mid + 1;

        // Number of right-half elements that have moved before current left element
        int rightCount = 0;

        while (left <= mid && right <= high) {

            // Left element is smaller (or equal)
            if (arr[left].first <= arr[right].first) {

                // All rightCount elements are smaller than this left element
                ans[arr[left].second] += rightCount;

                temp.push_back(arr[left]);
                left++;
            }

            // Right element is smaller
            else {

                // One more smaller element has crossed
                rightCount++;

                temp.push_back(arr[right]);
                right++;
            }
        }

        // Remaining left elements
        while (left <= mid) {
            ans[arr[left].second] += rightCount;
            temp.push_back(arr[left]);
            left++;
        }

        // Remaining right elements
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy back
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int low, int high,
                   vector<int>& ans) {

        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid, ans);

        mergeSort(arr, mid + 1, high, ans);

        merge(arr, low, mid, high, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 0);

        vector<pair<int, int>> arr;

        // Store value and original index
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, ans);

        return ans;
    }
};