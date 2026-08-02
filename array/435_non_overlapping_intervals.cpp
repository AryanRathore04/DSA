// Leetcode 435. Non-overlapping Intervals
// Time Complexity: O(n log n) - Due to sorting the intervals
// Space Complexity: O(1) - Constant space used for variables

// Approach:
// 1. Sort the intervals based on the starting times.
// 2. Initialize a counter to keep track of the number of intervals to remove and a variable to store the end time of the previous interval.
// 3. Iterate through the sorted intervals starting from the second interval. For each interval, check if it overlaps with the previous interval.
// 4. If it overlaps, increment the counter and update the end time to the minimum of the current interval's end time and the previous interval's end time.
// 5. If it does not overlap, update the end time to the current interval's end time.
// 6. Return the counter which represents the minimum number of intervals to remove to make the rest non-overlapping.

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(intervals[i][0] < prevEnd){
                prevEnd = min(prevEnd, intervals[i][1]);
                count++;
            }
            else{
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};