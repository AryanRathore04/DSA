// Problem: Given an array of integers, count the number of inversions in the array. An inversion is a pair of indices (i, j) such that i < j and arr[i] > arr[j]. Optimal solution using merge sort algorithm.

// Time Complexity: O(n log n)
// Space Complexity: O(n)

// Approach: The idea is to use the merge sort algorithm to count the number of inversions in the array. During the merge step, we can count the number of inversions by comparing the elements of the left and right halves of the array. If an element in the left half is greater than an element in the right half, then all remaining elements in the left half will also be greater than that element in the right half, and we can count those inversions.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp; // temporary array
        int left = low; // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr
        int inv_count = 0; // number of inversions
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                inv_count += (mid - left + 1); // number of inversions
                right++;
            }
        }
        // Copy the remaining elements of left half, if there are any
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        // Copy the remaining elements of right half, if there are any
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        // Copy the merged elements back to the original array
        for(int i = low; i <= high; i++){
            arr[i] = temp[i - low];
        }
        return inv_count;
    }

    int mergeSort(vector<int> &arr, int low, int high){
        int inv_count = 0;
        if(low < high){
            int mid = (low + high) / 2;
            inv_count += mergeSort(arr, low, mid); // left half
            inv_count += mergeSort(arr, mid + 1, high); // right half
            inv_count += merge(arr, low, mid, high); // merge the two halves
        }
        return inv_count;
    }

    int countInversions(vector<int> &arr){
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 20, 6, 4, 5};
    int result = solution.countInversions(arr);
    cout << "Number of inversions are: " << result << endl;
    return 0;
}