// Problem: Find the single element in a sorted array where every other element appears twice
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: 1. Initialize low and high pointers to the start and end of the array respectively.
// 2. While low is less than or equal to high, calculate the mid index
// 3. If the mid element is not equal to its neighbors, then it is the single element, so we return it
// 4. If the mid element is equal to its left neighbor and mid is odd, or if the mid element is equal to its right neighbor and mid is even, then the single element is in the right half of the array, so we update low to mid + 1
// 5. Otherwise, the single element is in the left half of the array, so we update high to mid - 1
// 6. Return -1 if no single element is found (this line will never be reached if the input is valid as per the problem statement)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int singleNonDuplicate(vector<int>& arr){
        int n = arr.size();

        if(n == 1) return arr[0];
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];

        int low = 1, high = n-2;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];

            // We are in left half
            if(mid % 2 == 1 && arr[mid] == arr[mid-1] || (mid % 2 == 0 && arr[mid] == arr[mid+1])){
                low = mid + 1;
            }
            // We are in right half
            else{
                high = mid - 1;
            }
        }
        return -1; // This line will never be reached if the input is valid as per the problem statement
    }
};

int main(){
    Solution findSingle;
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int result = findSingle.singleNonDuplicate(arr);
    cout << "The single element in the sorted array is: " << result << endl;
    return 0;
}