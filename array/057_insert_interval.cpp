//Leetcode 57. Insert Interval
// Time Complexity: O(n) - We are iterating through the intervals once.
// Space Complexity: O(n) - For storing the merged intervals in the answer vector   

// Approach:
// 1. Initialize a vector to store the answer intervals.
// 2. Iterate through the given intervals and for each interval, check if it overlaps with the new interval.
// 3. If it does not overlap, add the current interval to the answer vector.
// 4. If it overlaps, merge the intervals by updating the start and end of the new interval.
// 5. After iterating through all intervals, if the new interval has not been inserted, add it to the answer vector.
// 6. Return the answer vector containing the merged intervals

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> ans;

        int start = newInterval[0];
        int end = newInterval[1];

        bool inserted = false;

        for (int i = 0; i < n; i++)
        {
            if (intervals[i][1] < start)
            {
                ans.push_back(intervals[i]);
            }
            else if (intervals[i][0] > end)
            {
                if (!inserted)
                {
                    ans.push_back({start, end});
                    inserted = true;
                }

                ans.push_back(intervals[i]);
            }
            else
            {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }

        if (!inserted)
        {
            ans.push_back({start, end});
        }

        return ans;
    }
};