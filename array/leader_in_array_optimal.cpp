// Leader in an array optimal approach
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach:
// 1. Initialize a variable to keep track of the maximum element seen so far.
// 2. Iterate through the array from right to left.
// 3. If the current element is greater than the maximum element seen so far, it is a leader. Add it to the result array and update the maximum element.
// 4. Return the result array.

#include<vector>
#include<iostream>
#include<climits>
using namespace std;

class Solution{
    public:
    vector<int> superiorElement(vector<int> &a){
        int maxi = INT_MIN;
        int n = a.size();
        vector<int> ans;
        for(int i = n -1; i >= 0; i--){
         if(a[i] > maxi){
            ans.push_back(a[i]);
         }
            maxi = max(maxi, a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = s.superiorElement(nums);
    
    for(int leader : leaders){
        cout << leader << " ";
    }
    
    return 0;
}