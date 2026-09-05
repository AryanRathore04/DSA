// Problem: Median of Two Sorted Arrays Brute Force Approach
// Time Complexity: O(n + m) where n and m are the sizes of the two arrays
// Space Complexity: O(n + m) for the merged array

// Approach: 1. Initialize two pointers i and j to 0, which will be used to traverse the two arrays.
// 2. Create an empty vector merged to store the merged elements of the two arrays.
// 3. While both pointers are within the bounds of their respective arrays, compare the elements at the pointers. Append the smaller element to the merged vector and increment the corresponding pointer.
// 4. If there are remaining elements in either array after the main loop, append them to the merged vector.
// 5. Calculate the total number of elements in the merged array. If the total number is even, return the average of the two middle elements. If it is odd, return the middle element.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    double median(vector<int>& a, vector<int>& b){
        vector<int> merged;
        int n1 = a.size();
        int n2 = b.size();
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            if(a[i] < b[j]){
                merged.push_back(a[i++]);
                
            } else {
                merged.push_back(b[j++]);
            }
        }
        while(i < n1){
            merged.push_back(a[i++]);
            
        }
        while(j < n2){
            merged.push_back(b[j++]);
        }

        int n = n1 + n2;
        if(n % 2 == 1){
            return merged[n/2];
        }

        return (double)((double)merged[n/2]) + (double)merged[n/2 - 1] / 2.0;

    }
};

int main(){
    Solution s;
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout << s.median(a, b) << endl; // Output: 2.0

    vector<int> c = {1, 2};
    vector<int> d = {3, 4};
    cout << s.median(c, d) << endl; // Output: 2.5

    return 0;
}