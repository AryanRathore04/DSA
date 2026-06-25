// Problem: Sort an array of 0s, 1s and 2s
// Time Complexity: O(2n)
// Space Complexity: O(1)

// Approach: Count the number of 0s, 1s and 2s in the array and then fill the array with the counted values.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
        void sortnumbers(vector<int>& nums){
                int cnt0 = 0;
                int cnt1 = 0;
                int cnt2 = 0;

            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0) cnt0++;
                else if(nums[i] == 1) cnt1++;
                else cnt2++;
            }

        for(int i = 0; i< cnt0; i++) nums[i] = 0;
        for(int i = cnt0; i< cnt0 + cnt1; i++) nums[i] = 1;
        for(int i = cnt0 + cnt1; i< nums.size(); i++) nums[i] = 2;
        }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 1, 2, 1, 0};
    solution.sortnumbers(nums);
    // nums is now sorted: {0, 0, 1, 1, 2, 2}

        for (int num : nums) {
                cout << num << " ";
        }
        cout << endl;

    return 0;
}