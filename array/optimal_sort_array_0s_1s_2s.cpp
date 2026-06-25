#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
        void sortArray(vector<int>& nums, int n){
         int low = 0, mid = 0, high = n-1;
         while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
           else if(nums[mid] == 1){
                mid++;
            }

            else{
                swap(nums[mid], nums[high]);
                high--;
            }
         }
}
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 1, 2, 1, 0};
    int n = nums.size();
    solution.sortArray(nums, n);
    // nums is now sorted: {0, 0, 1, 1, 2, 2}

        for (int num : nums) {
                cout << num << " ";
        }
        cout << endl;

    return 0;
}