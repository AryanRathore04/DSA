// Problem: Longest Consecutive Sequence Better Solution
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

// Approach: We first sort the array and then iterate through it to find the longest consecutive sequence. We keep track of the last smaller element and count the length of the current consecutive sequence. If we encounter a non-consecutive element, we reset the count. We also handle duplicates by checking if the current element is equal to the last smaller element.

#include<vector>
#include<iostream>
#include<unordered_set>
#include<climits>
using namespace std;

class Solution {
    public:
    int longestSuccessiveElements(vector<int>& nums){
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] - 1 == lastSmaller){
                cnt++;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i]){
                cnt = 1;
                lastSmaller = nums[i];
            }

            longest = max(longest, cnt);
        }
        return longest;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = solution.longestSuccessiveElements(nums);
    cout << result << '\n';
    return 0;
}