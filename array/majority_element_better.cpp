// Majority Element Better Solution
// Time Complexity: O(N log N) + O(N) = O(N log N)
// Space Complexity: O(n)

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
    public:
    int majorityElement(vector<int> &nums){
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto it: mpp){
            if(it.second > (nums.size() / 2)){
                return it.first;
            }
        }
        return -1; // Return -1 if no majority element is found
    }
};

int main(){
    Solution solution;
    vector<int> nums = {3, 2, 3};
    int result = solution.majorityElement(nums);
    cout << "Majority Element: " << result << endl;
    return 0;
}

