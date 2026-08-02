// Problem: Merge two sorted arrays without extra space Optimal approach 1
// Time Complexity: O((n + m) log(n + m)) where n and m are the sizes of the two arrays
// Space Complexity: O(1) as we are not using any extra space for merging

// Approach: Use two pointers to traverse both arrays and swap elements when necessary, then sort both arrays.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    void merge(long long nums1[], int n, long long nums2[], int m){
        int left = n - 1;
        int right = 0;

        while(left >= 0 && right < m){
            if(nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else{
                break;
            }

         
        }
        sort(nums1, nums1 + n);
        sort(nums2, nums2 + m);
    }
}; 

int main(){
    Solution solution;
    long long nums1[] = {1, 3, 5, 7};
    long long nums2[] = {0, 2, 6, 8, 9};
    int n = sizeof(nums1) / sizeof(nums1[0]);
    int m = sizeof(nums2) / sizeof(nums2[0]);
    solution.merge(nums1, n, nums2, m);
    
    // Merging the two arrays into a single sorted array for display
    vector<long long> mergedArray;
    mergedArray.insert(mergedArray.end(), nums1, nums1 + n);
    mergedArray.insert(mergedArray.end(), nums2, nums2 + m);
    sort(mergedArray.begin(), mergedArray.end());

    // Displaying the merged array
    cout << "Merged array: ";
    for (long long num : mergedArray) {
        cout << num << " "; 
    }
    cout << endl;

    return 0;


}