// LeetCode 485
// Max Consecutive Ones
// Topic: Arrays
// Pattern: Running Count + Running Maximum
// Time Complexity: O(n)
// Space Complexity: O(1)

// Idea:
// count -> current streak of 1s
// maxi -> largest streak seen so far
// if 1 -> increase streak
// if 0 -> reset streak

#include <vector>;
#include <algorithm>;
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == 1){

                count++;

                maxi = max(maxi, count);
            }

            else{

                count = 0;
            }
        }

        return maxi;
    }
};