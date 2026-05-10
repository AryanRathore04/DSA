// LeetCode 26
// Remove Duplicates from Sorted Array
// Topic: Arrays, Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

// Idea:
// i -> tracks unique section
// j -> scans array
// when new unique found:
// nums[i+1] = nums[j]

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