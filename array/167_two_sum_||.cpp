// Leetcode 167. Two Sum II - Input Array Is Sorted
// Time Complexity: O(n)
// Space Complexity: O(1)

// Explanation: We can use two pointers to find the two numbers that add up to the target. We start with one pointer at the beginning of the array and the other at the end. We calculate the sum of the two numbers at these pointers. If the sum is equal to the target, we return their indices (1-based). If the sum is less than the target, we move the left pointer to the right to increase the sum. If the sum is greater than the target, we move the right pointer to the left to decrease the sum. We continue this process until we find the pair or until the pointers cross each other.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left + 1, right + 1};
            }
            else if(sum < target) left++;
            else right--;
        }

        return {};
    }
};