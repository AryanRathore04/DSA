// Leetcode 229. Majority Element II
// Time Complexity: O(n)
// Space Complexity: O(1)

// Explanation: The problem is to find all elements in an array that appear more than n/3 times. The solution uses the Boyer-Moore Voting Algorithm to find up to two potential majority elements, and then counts their actual frequencies to determine if they meet the required condition.


#include <vector>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1 = 0;
        int element2 = 0;
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < nums.size(); i++) { 
             if (element1 == nums[i]) {
                count1++;
            } else if (element2 == nums[i]) {
                count2++;
            }
            else if(count1 == 0) {
                element1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                element2 = nums[i];
                count2++; 
            }
            else {
                count1--;
                count2--;
            }
        }

        int countfrequency1 = 0;
        int countfrequency2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (element1 == nums[i]) {
                countfrequency1++;
            }

            if (element2 == nums[i]) {
                countfrequency2++;
            }
        }

        vector<int> ans;
        if (countfrequency1 > nums.size() / 3) {
            ans.push_back(element1);
        }
        if (countfrequency2 > nums.size()/3 && element2 != element1) {
            ans.push_back(element2);
        }

        return ans;
    }
};