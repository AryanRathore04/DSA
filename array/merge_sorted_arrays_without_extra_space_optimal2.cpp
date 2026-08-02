// Problem: Merge two sorted arrays without using extra space Optimal approach 2
// Time Complexity: O((n + m) log(n + m)) where n and m are the sizes of the two arrays
// Space Complexity: O(1) as we are not using any extra space for merging

// Approach: 1. Calculate the initial gap value as (n + m) / 2 + (n + m) % 2.
// 2. Compare elements at the current gap distance and swap them if they are out of order.
// 3. Reduce the gap value and repeat the process until the gap becomes 0.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    private:
    void swapIfGreater(long long arr1[], long long arr2[],int ind1, int ind2){
        if(arr1[ind1] > arr2[ind2]){
            swap(arr1[ind1], arr2[ind2]);
        }
    }
    public:
    void merge(long long arr1[], long long arr2[], int n, int m){
        int len = n + m;
        int gap = (len / 2) + (len % 2);
        while(gap > 0){
            int left = 0;
            int right = left + gap;
            
            while(right < len){
                // arr1 and arr2
                if(left < n && right >= n){

                    swapIfGreater(arr1, arr2, left, right - n);
                }
                // arr2 and arr2
                else if(left >= n){

                    swapIfGreater(arr1, arr2, left - n, right - n);
                }
                // arr1 and arr1
                else{
                    swapIfGreater(arr1, arr2, left, right);
                }
                left++, right++;
            }
            if(gap == 1){
                gap = 0;
            }
            else{
                gap = (gap / 2) + (gap % 2);
            }
        }
    }
};

int main(){
    Solution solution;
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    solution.merge(arr1, arr2, n, m);
    
    // Merging the two arrays into a single sorted array for display
    vector<long long> mergedArray;
    mergedArray.insert(mergedArray.end(), arr1, arr1 + n);
    mergedArray.insert(mergedArray.end(), arr2, arr2 + m);
    sort(mergedArray.begin(), mergedArray.end());

    // Displaying the merged array
    cout << "Merged array: ";
    for (long long num : mergedArray) {
        cout << num << " "; 
    }
    cout << endl;

    return 0;
}