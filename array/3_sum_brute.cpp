// Problem: Given an array of integers, find all unique triplets in the array which gives the sum of zero.
// Time Complexity: O(n^3) - The three nested loops iterate through the array to find all possible triplets.
// Space Complexity: O(n) - The set is used to store unique triplets, which can take up to O(n) space in the worst case.

// Approach: The brute-force approach involves using three nested loops to iterate through all possible triplets in the array. For each triplet, we check if the sum is zero. To avoid duplicates, we store the triplets in a set after sorting them. Finally, we convert the set to a vector and return it as the result.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
    public:
    vector<vector<int>> tripletSum(int n, vector<int> &num){
        set<vector<int>> uniqueTriplets; // This is used to avoid duplicate triplets

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(num[i] + num[j] + num[k] == 0){

                        // The under three lines shows that we are storing the triplet in a temporary vector, sorting it to handle duplicates, and then inserting it into a set to ensure uniqueness.
                        vector<int> temp = {num[i], num[j], num[k]};
                        sort(temp.begin(), temp.end()); // Sort the triplet to handle duplicates
                        uniqueTriplets.insert(temp); // Insert the triplet into the set
                    }
                }
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