// Problem: Search an element in a rotated sorted array with unique elements

// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: We can use binary search to find the element in the rotated sorted array. We will check if the left half or right half is sorted and then decide which half to search based on the value of the target element.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int search(vector<int>& arr, int n, int k){
        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(arr[mid] == k){
                return mid;
            }

            // left half is sorted
            if(arr[low] <= arr[mid]){
                if(k >= arr[low] && k <= arr[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            // right half is sorted
            else{
                if(k >= arr[mid] && k <= arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();
    int k = 0;
    int result = obj.search(arr, n, k);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    }
    else{
        cout << "Element not found in the array." << endl;
    }
    return 0;
}