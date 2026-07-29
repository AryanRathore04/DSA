// Problem: 4Sum Optimal Approach
// Time Complexity: O(n^3) - The three nested loops iterate through the array to find all possible triplets for each fixed pair of numbers, and the two-pointer approach is O(n) on average
// Space Complexity: O(1) - The space used is constant as we are not using any additional data structures that grow with input size, except for the result vector which is required to store the output quadruplets.

// Approach: The optimal approach involves fixing two numbers and then using the two-pointer technique to find pairs that sum up to the difference between the target and the sum of the fixed numbers. This reduces the time complexity from O(n^4) to O(n^3). We also skip duplicates to avoid duplicate quadruplets in the result.

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first number
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for the second number
                int left = j + 1; // Initialize the left pointer for the two-pointer approach
                int right = n - 1; // Initialize the right pointer for the two-pointer approach

                while(left < right){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[left];
                    sum += nums[right];

                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[left], nums[right]}; // Create a quadruplet with the current numbers
                        result.push_back(temp); // Add the quadruplet to the result vector
                        left++; // Move the left pointer to the right to find the next potential quadruplet
                        right--; // Move the right pointer to the left to find the next potential quadruplet

                        while(left < right && nums[left] == nums[left - 1]) left++; // Skip duplicates
                        while(left < right && nums[right] == nums[right + 1]) right--; // Skip duplicates
                    }
                    else if(sum < target){
                        left++; // Move the left pointer to the right to increase the sum
                    }
                    else{
                        right--; // Move the right pointer to the left to decrease the sum
                    }
                }
            }
        }

        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 1, 0, 1};
    int target = 5;
    vector<vector<int>> result = sol.fourSum(nums, target);
    
    for(const auto& quad : result){
        for(int num : quad){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}