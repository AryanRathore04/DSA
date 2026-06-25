#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicates(vector<int>& nums){
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++){
            if(seen.find(nums[i]) != seen.end()){
                return true;
            } else {
                seen.insert(nums[i]);
            }
        }
        return false;       
    }
};