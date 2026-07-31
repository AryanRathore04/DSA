// Problem: Merge Overlapping Intervals Optimal Approach
// Time Complexity: O(n log n) - Due to sorting the intervals
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
            // If the answer vector is empty or the current interval does not overlap with the last interval in ans, add it to ans
            if(ans.empty() || arr[i][0] > ans.back()[1]){
                ans.push_back(arr[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], arr[i][1]); // Merge the current interval with the last interval in ans
            }
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

