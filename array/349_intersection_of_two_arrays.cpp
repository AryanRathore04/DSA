// Leetcode 349. Intersection of Two Arrays
// Time Complexity: O(n + m), where n is the length of nums1 and m is the length of nums2
// Space Complexity: O(n), where n is the length of nums1

// Approach: Use a hash set to store the elements of the first array. Then, iterate through the second array and check if each element is in the hash set. If it is, add it to the result vector and remove it from the hash set to avoid duplicates.

#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen;

        for (int i = 0; i < nums1.size(); i++) {
            seen.insert(nums1[i]);
        }

        vector<int> ans;

        for (int i = 0; i < nums2.size(); i++) {
            if (seen.find(nums2[i]) != seen.end()) {
                ans.push_back(nums2[i]);

                seen.erase(nums2[i]);
            }
        }

        return ans;
    }
};