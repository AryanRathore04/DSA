//Leetcode 18. 4Sum
// Time Complexity: O(n^3)
// Space Complexity: O(1)

// Approach: The optimal approach involves fixing two numbers and then using the two-pointer technique to find pairs that sum up to the difference between the target and the sum of the fixed numbers. This reduces the time complexity from O(n^4) to O(n^3). We also skip duplicates to avoid duplicate quadruplets in the result.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int a = 0; a < n; a++){
            if(a > 0 && nums[a] == nums[a - 1]) continue;
            for(int b = a + 1; b < n; b++){
                if(b > a + 1 && nums[b] == nums[b - 1]) continue;

                int c = b + 1;
                int d = n - 1;

                while(c < d){
                    long long sum = nums[a];
                    sum += nums[b];
                    sum += nums[c];
                    sum += nums[d];

                    if(sum == target){
                        vector<int> temp = {nums[a], nums[b], nums[c], nums[d]};
                        result.push_back(temp);
                        c++;
                        d--;

                        while(c < d && nums[c] == nums[c - 1]) c++;
                        while(c < d && nums[d] == nums[d + 1]) d--;
                    }
                    else if(sum < target){
                        c++;
                    }
                    else{
                        d--;
                    }
                }
            }
        }

        return result;
    }
};