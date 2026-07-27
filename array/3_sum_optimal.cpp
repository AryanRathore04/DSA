// 3 sum problem using the two-pointer technique
// Time Complexity: O(n^2) - The outer loop runs n times and the inner while loop runs at most n times in total for each iteration of the outer loop, leading to a quadratic time complexity.
// Space Complexity: O(1) - We are using a constant amount of extra space for variables and the output vector, which does not depend on the input size.

// Approach: The optimized approach involves sorting the array and then using two pointers to find pairs that sum up to the negative of the fixed number. This reduces the time complexity from O(n^3) to O(n^2). We also skip duplicates to ensure unique triplets are found.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<vector<int>> tripletSum(int n, vector<int> &num){
        vector<vector<int>> ans; // This will store the final unique triplets;
        sort(num.begin(), num.end()); // Sort the array to make it easier to avoid duplicates and use two pointers

        for(int i = 0; i < n; i++){ // Fix the first number of the triplet
            if(i > 0 && num[i] == num[i - 1]) continue; // Skip duplicates for the first number

            int j = i + 1; // Initialize the second pointer
            int k = n - 1; // Initialize the third pointer

            while(j < k){ // While the second pointer is less than the third pointer
                int sum = num[i] + num[j] + num[k]; // Calculate the sum of the triplet

                if(sum < 0){ // If the sum is less than zero, we need a larger number, so we move the second pointer to the right
                    j++;
                }
                else if(sum > 0){ // If the sum is greater than zero, we need a smaller number, so we move the third pointer to the left
                    k--;
                }
                else{ // If the sum is equal to zero, we found a triplet
                    vector<int> temp = {num[i], num[j], num[k]}; // Create a triplet with the current numbers
                    ans.push_back(temp); // Add the triplet to the answer
                    j++; // Move the second pointer to the right
                    k--; // Move the third pointer to the left

                    while(j < k && num[j] == num[j-1]) j++; // Skip duplicates for the second number
                    while(j < k && num[k] == num[k+1]) k--; // Skip duplicates for the third number


                }
            }
        }

        return ans;
    }
};


int main() {
    Solution solution;
    vector<int> num = {-1, 0, 1, 2, -1, -4};
    int n = num.size();
    vector<vector<int>> result = solution.tripletSum(n, num);

    // Print the result
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}