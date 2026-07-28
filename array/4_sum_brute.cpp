// Problem: 4Sum Brute Force Approach
// Time Complexity: O(n^4) - The four nested loops iterate through the array to find all possible quadruplets.
// Space Complexity: O(n) - The set is used to store unique quadruplets, which can take up to O(n) space in the worst case.

// Approach: The brute-force approach involves using four nested loops to iterate through all possible quadruplets in the array. For each quadruplet, we check if the sum is equal to the target. To avoid duplicates, we store the quadruplets in a set after sorting them. Finally, we convert the set to a vector and return it as the result.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
    public:
    vector<vector<int>> fourSum(vector<int>&nums, int target){
        int n = nums.size();
        set<vector<int>> uniqueQuadruplets; // This is used to avoid duplicate quadruplets

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int l = k + 1; l < n; l++){
                        // Calculate the sum of first two numbers and then add then add the third and fourth numbers to check if it equals the target
                        long long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if(sum == target){
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end()); // Sort the quadruplet to handle duplicates
                            uniqueQuadruplets.insert(temp);
                        }

                    }
                }
            }
        }
        // Convert the set to a vector and return
        return vector<vector<int>>(uniqueQuadruplets.begin(), uniqueQuadruplets.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);

    // Print the result
    for (const auto& quadruplet : result) {
        cout << "[";
        for (size_t i = 0; i < quadruplet.size(); ++i) {
            cout << quadruplet[i];
            if (i < quadruplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}