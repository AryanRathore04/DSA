// Problem: Given an array of integers, find all unique triplets in the array which gives the sum of zero.
// Time Complexity: O(n^2) - The two nested loops iterate through the array to find all possible pairs for each fixed number, and the set operations are O(log n) on average
// Space Complexity: O(n) - The set is used to store unique triplets, which can take up to O(n) space in the worst case, and the seen set can also take up to O(n) space in the worst case.

// Approach: The optimized approach involves fixing one number and then using a set to find pairs that sum up to the negative of the fixed number. This reduces the time complexity from O(n^3) to O(n^2). We also use a set to store unique triplets to avoid duplicates.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
    public:
    vector<vector<int>> tripletSum(int n, vector<int> &num){
        set<vector<int>> uniqueTriplets; // This is used to avoid duplicate triplets

        for(int i = 0; i < n; i++){
            set<int> seen; // This set is used to keep track of the numbers we have seen so far in the inner loop and it also empty after each iteration of the outer loop. This is important because we want to find unique pairs for each fixed number num[i].


            for(int j = i + 1; j < n; j++){
                int third = -(num[i] + num[j]); // Calculate the required third number to make the sum zero

                if(seen.find(third) != seen.end()){ // Check if the required third number is already in the seen set
                    vector<int> temp = {num[i], num[j], third}; // Create a triplet with the current numbers
                    sort(temp.begin(), temp.end()); // Sort the triplet to handle duplicates
                    uniqueTriplets.insert(temp); // Insert the triplet into the set
                }

                seen.insert(num[j]); // Insert the current number into the seen set
            }
        }

        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end()); // Convert the set to a vector for the final answer
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