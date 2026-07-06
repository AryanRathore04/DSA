// Problem: Longest Consecutive Sequence Brute Force
// Time Complexity: O(n^3)
// Space Complexity: O(1)

// Approach: For each element in the array, we check for the next consecutive elements by incrementing the current element and checking if it exists in the array. We keep track of the count of consecutive elements and update the longest count found.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool ls(vector<int>& nums, int x);

class Solution {
    public:
    int longestConsecutive(vector<int>& nums){
        if(nums.empty()) return 0;
        int longest = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int cnt = 1;
            while(ls(nums, x + 1)){
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};

// Helper function to check if an element exists in the vector
bool ls(vector<int>& nums, int x){
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == x) return true;
    }
    return false;
}

int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = solution.longestConsecutive(nums);
    cout << result << '\n';
    return 0;
}
