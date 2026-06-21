// 350. Intersection of Two Arrays II
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(n)

// Explanation:
// 1. Create a hash map to store the frequency of elements in nums1.
// 2. Traverse through nums2 and check if the element exists in the hash map.
//  3. If it exists, add it to the result vector and decrement the frequency in the hash map.   

#include <vector>;
#include <algorithm>;
#include <unordered_map>;
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;

        //First loop for nums 1 for go though every method
        for(int i = 0; i < nums1.size(); i++){
            mpp[nums1[i]]++;
        }

        vector<int> ans;

        // This loop is for tranverse nums2
        for(int i = 0; i < nums2.size(); i++){
            if(mpp[nums2[i]] > 0){
                ans.push_back(nums2[i]);
            }

            mpp[nums2[i]]--;
        }
    return ans;
    }

};

