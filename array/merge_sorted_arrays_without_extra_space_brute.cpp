// Problem: Merge two sorted arrays without using extra space Brute Force Approach
// Time Complexity: O(n + m) - Due to the merging of two arrays
// Space Complexity: O(n + m) - For storing the merged array in arr3    

// Approach:
// 1. Create a new array arr3 of size n + m to store the merged elements.
// 2. Use two pointers, left and right, to traverse through arr1 and arr2 respectively.
// 3. Compare the elements pointed by left and right pointers and insert the smaller element into arr3, then move the corresponding pointer forward.
// 4. If one of the arrays is exhausted, copy the remaining elements from the other array into arr3.
// 5. Finally, copy the elements from arr3 back into arr1 and arr2 to maintain the sorted order without using extra space in the original arrays.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public: 
    void merge(long long arr1[], long long arr2[], int n, int m){
        long long arr3[n + m];
        int left = 0;
        int right = 0;
        int index = 0;

        while(left < n && right < m){
            if(arr1[left] <= arr2[right]){
                arr3[index] = arr1[left];
                left++, index++;
            }
            else{
                arr3[index] = arr2[right];
                right++, index++;
            }
        }

        while(left < n){
            arr3[index++] = arr1[left++];
        }
        while(right < m){
            arr3[index++] = arr2[right++];
        }

        for(int i = 0; i< n + m; i++){
            if(i < n){
                arr1[i] = arr3[i];
            }
            else{
                arr2[i - n] = arr3[i];
            }
        }
    }
};

int main(){
    Solution solution;
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {2, 4, 6, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    solution.merge(arr1, arr2, n, m);

    cout << "Merged Arrays: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }
    for(int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}