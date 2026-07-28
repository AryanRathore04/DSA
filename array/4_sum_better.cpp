// Problem: 4Sum Better Approach
// Time Complexity: O(n^3) - The three nested loops iterate through the array to find all possible triplets for each fixed pair of numbers, and the set operations are O(log n) on average
// Space Complexity: O(n) - The set is used to store unique quadruplets, which can take up to O(n) space in the worst case, and the seen set can also take up to O(n) space in the worst case.

// Approach: The optimized approach involves fixing two numbers and then using a set to find pairs that sum up to the difference between the target and the sum of the fixed numbers. This reduces the time complexity from O(n^4) to O(n^3). We also use a set to store unique quadruplets to avoid duplicates.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> uniqueQuadruplets; // This is used to avoid duplicate quadruplets

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                set<long long> seen; // This set is used to keep track of the numbers we have seen so far in the inner loop and it also empty after each iteration of the outer loop. This is important because we want to find unique pairs for each fixed number nums[i] and nums[j].
                for (int k = j + 1; k < n; k++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = (long long)target - (sum); // Calculate the required fourth number

                    if(seen.find(fourth) != seen.end()) // Check if the required fourth number is already in the seen set
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth}; // Create a quadruplet with the current numbers
                        sort(temp.begin(), temp.end()); // Sort the quadruplet to handle duplicates
                        uniqueQuadruplets.insert(temp); // Insert the quadruplet into the set
                    }

                    seen.insert(nums[k]); // Insert the current number into the seen set

                }
            }
        }
        return vector<vector<int>>(uniqueQuadruplets.begin(), uniqueQuadruplets.end());
    }
};