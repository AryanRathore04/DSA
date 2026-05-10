// LeetCode 27
// Remove Element
// Topic: Arrays, Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

// Idea:
// i -> scans array
// k -> stores valid elements at front
// keep elements != val

#include <vector>;
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int k = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] != val){

                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};