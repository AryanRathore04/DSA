// Leetcode 56. Merge Intervals
// Time Complexity: O(n log n) - Due to sorting the intervals
// Space Complexity: O(n) - For storing the merged intervals in the answer vector

// Approach:
// 1. Sort the intervals based on the starting times.
// 2. Iterate through the sorted intervals and for each interval, check if it overlaps with the last interval in the answer vector.
// 3. If it overlaps, merge them by updating the end time of the last interval in the answer vector.
// 4. If it does not overlap, add the current interval to the answer vector.
// 5. Return the answer vector containing merged intervals.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};