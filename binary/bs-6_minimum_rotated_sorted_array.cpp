// Problem: Find the minimum element in a rotated sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: We can use binary search to find the minimum element in the rotated sorted array. We will check if the left half or right half is sorted and then decide which half to search based on the values of the elements.

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

        while(low <= high){
            int mid = low + (high - low) / 2;
            // Left half is sorted
            if(arr[mid] >= arr[low]){
                ans = min(ans, arr[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else{
                high = mid - 1;
                ans = min(ans, arr[mid]);
            }
        }

        return ans;
    }
};

int main(){
    Solution findMin;
    vector<int> arr = {4, 5, 6, 7, 1, 2};
    int result = findMin.findMin(arr);
    cout << "Minimum element in the rotated sorted array: " << result << endl;
    return 0;
}