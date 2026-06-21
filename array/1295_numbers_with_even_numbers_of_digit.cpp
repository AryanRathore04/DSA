// Leetcode 1295. Find Numbers with Even Number of Digits
// Time Complexity: O(n)
// Space Complexity: O(1)

// Explanation: We can iterate through the array and for each number, we can count the number of digits in it. If the count is even, we increment our answer.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
            int count = 0;
            int num = nums[i];
            while (num > 0) {
                count++;
                num /= 10;
            }

            if (count % 2 == 0) {
                ans++;
            }
        }

        return ans;
    }
};