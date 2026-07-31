// Problem: Merge Overlapping Intervals Brute Force Approach
// Time Complexity: O(n^2) - Due to the nested loops for merging intervals
// Space Complexity: O(n) - For storing the merged intervals in the answer vector

// Approach:
// 1. Sort the intervals based on the starting times.
// 2. Iterate through the sorted intervals and for each interval, check if it overlaps with the last interval in the answer vector.
// 3. If it overlaps, merge them by updating the end time of the last interval in the answer vector.
// 4. If it does not overlap, add the current interval to the answer vector.
// 5. Return the answer vector containing merged intervals.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            int start = arr[i][0]; // Start of the current interval
            int end = arr[i][1]; // End of the current interval

            if(!ans.empty() && end <= ans.back()[1]){
                continue; // Current interval is completely within the last interval in ans
            }

            for(int j = i + 1; j < n; j++){
                if(arr[j][0] <= end){
                    end = max(end, arr[j][1]); // Extend the end of the current interval
                } else {
                    break; // No more overlapping intervals
                }
            }

            ans.push_back({start, end}); // Add the merged interval to ans
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    vector<vector<int>> mergedIntervals = solution.mergeOverlappingIntervals(intervals);

    cout << "Merged Intervals: " << endl;
    for (const auto &interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}