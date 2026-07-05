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