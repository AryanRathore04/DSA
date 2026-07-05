// Find all the leaders in an array using brute force approach

// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Approach:
// 1. Iterate through the array from left to right.
// 2. For each element, check if it is greater than all the elements to its right.
// 3. If it is, add it to the result array.

#include<vector>
#include<iostream>
using namespace std;

class Solution{
    public:
    vector<int> leaderArray(vector<int> nums){
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int leader = true;

            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] > nums[i]){
                    leader = false;
                    break;
                }
            }
            
            if(leader == true){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = s.leaderArray(nums);
    
    for(int leader : leaders){
        cout << leader << " ";
    }
    
    return 0;
}