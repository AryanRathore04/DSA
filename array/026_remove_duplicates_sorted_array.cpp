// LeetCode 26
// Remove Duplicates from Sorted Array
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>;
using namespace std;


    class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;

        for(int j = 1; j < nums.size(); j++){

            if(nums[i] != nums[j]){

                nums[i+1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }
};