// Problem: Find out how many times array has been rotated
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: 1. Initialize low and high pointers to the start and end of the array respectively.
// 2. While low is less than or equal to high, calculate the mid index
// 3. If the mid element is less than or equal to the high element, then the minimum element is in the left half of the array, so we update high to mid - 1 and update the answer to the minimum of the current answer and the mid element
// 4. If the mid element is greater than the high element, then the minimum element is in the right half of the array, so we update low to mid + 1 and update the answer to the minimum of the current answer and the mid element
// 5. Return the index of the minimum element which represents how many times the array has been rotated

// Note: The number of times the array has been rotated is equal to the index of the minimum element in the rotated sorted array.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    int findMin(vector<int>& arr){
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        int index = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(arr[low] <= arr[high]){
                if(arr[low] < ans){
                    index = low;
                    ans = arr[low];
                }
                break;
            }


            // Left half is sorted
            if(arr[mid] >= arr[low]){
                if(arr[low] < ans){
                    index = low;
                    ans = arr[low];
                }
                low = mid + 1;
            }
            // Right half is sorted
            else{
                high = mid - 1;
                if(arr[mid] < ans){
                    index = mid;
                    ans = arr[mid];
                }
            }
        }

        return index;
    }
};

int main(){
    Solution findMin;
    vector<int> arr = {4, 5, 6, 7, 1, 2};
    int result = findMin.findMin(arr);
    cout << "Number of times the array has been rotated: " << result << endl;
    return 0;
}