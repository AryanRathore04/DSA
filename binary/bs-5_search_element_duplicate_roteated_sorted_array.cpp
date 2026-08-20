// Problem: Find an element in a rotated sorted array with duplicates

// Time Complexity: O(log n) in average case, O(n) in worst case
// Space Complexity: O(1)

// Approach: We can use binary search to find the element in the rotated sorted array. We will check if the left half or right half is sorted and then decide which half to search based on the value of the target element. If we encounter duplicates, we will shrink the search space by moving the low and high pointers.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    bool searchInARotatedSortedArrayII(vector<int>& arr, int k){
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(arr[mid] == k){
                return true;
            }

            if(arr[low] == arr[mid] && arr[mid] == arr[high]){
                low++;
                high--;
            }
            // left half is sorted
            else if(arr[low] <= arr[mid]){
                if(k >= arr[low] && k <= arr[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
                // right half is sorted
            }
            else{
                if(k >= arr[mid] && k <= arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
    int k = 0;
    bool result = obj.searchInARotatedSortedArrayII(arr, k);
    if(result){
        cout << "Element found in the array." << endl;
    }
    else{
        cout << "Element not found in the array." << endl;
    }
    return 0;
}