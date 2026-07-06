// Problem: Longest Consecutive Sequence Optimal Solution
// Time Complexity: O(3N)
// Space Complexity: O(N)

// Approach: We use an unordered_set to store all the elements of the array. Then, for each element, we check if it is the start of a sequence (i.e., if the previous element does not exist in the set). If it is, we count the length of the consecutive sequence starting from that element and update the longest length found.

#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
    public:
    int longestSuccessiveElements(vector<int>& a){
        int n = a.size();
        if(n==0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++){
            st.insert(a[i]);
        }

        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = solution.longestSuccessiveElements(nums);
    cout << result << '\n';
    return 0;
}