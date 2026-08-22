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