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