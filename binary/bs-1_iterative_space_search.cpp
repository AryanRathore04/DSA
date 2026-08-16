#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int search(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0; // index of the first element
        int high = n-1; // index of the last element

        while(low <= high){
            int mid = (low + high) / 2; // index of the middle element

            if(nums[mid] == target) return mid;
            else if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 3;
    int result = solution.search(nums, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}