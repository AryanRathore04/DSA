// LeetCode problem: 128. Longest Consecutive Sequence
// Time Complexity: O(3N)
// Space Complexity: O(N)

// Approach: We use an unordered_set to store all the elements of the array. Then, for each element, we check if it is the start of a sequence (i.e., if the previous element does not exist in the set). If it is, we count the length of the consecutive sequence starting from that element and update the longest length found.

#include<vector>
#include <unordered_set>
using namespace std;    

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        if(n == 0) return 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x + 1) != st.end()){
                    cnt++;
                    x++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};