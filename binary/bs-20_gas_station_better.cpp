// Problem: Given an array of integers representing positions of gas stations along a straight road, and an integer k representing the number of additional gas stations that can be added, the task is to minimize the maximum distance between any two adjacent gas stations after adding the k new gas stations.
// Time Complexity: O(n log n + k log n), where n is the number of existing gas stations and k is the number of additional gas stations to be placed. The initial sorting of the array takes O(n log n) time, and for each of the k gas stations, we perform a log n operation to maintain the max-heap.
// Space Complexity: O(n), where n is the number of existing gas stations. We use an additional vector of size n-1 to keep track of how many gas stations are placed between each pair of existing stations, and a max-heap to keep track of the maximum section lengths.
// Approach: 1. Create a max-heap (priority queue) to keep track of the maximum section lengths and their indices. 
// 2. For each of the k gas stations to be placed, extract the section with the maximum length from the heap, place a gas station there, and update the section length in the heap. 
// 3. After placing all k gas stations, the maximum section length in the heap will be the minimized maximum distance between any two adjacent gas stations. 
// 4. The algorithm uses a greedy approach to place the gas stations in the sections with the maximum length, which ensures that the maximum distance between any two adjacent gas stations is minimized.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    public:
    long double minimiseMaxDistance(vector<int> &arr, int k){
        int n = arr.size();
        vector<int> howMany(n-1, 0);
        priority_queue<pair<long double, int>> pq; // Max-heap to keep track of the maximum section length and its index
        for(int i = 0; i < n-1; i++){
            long double diff = (arr[i+1] - arr[i]);
            pq.push({diff, i}); // Push the initial section lengths into the max-heap
        }

        for(int gasStation = 1; gasStation <= k; gasStation++){
            auto tp = pq.top(); // Get the section with the maximum length
            pq.pop(); // Remove it from the heap
            int maxIndex = tp.second; // 
            howMany[maxIndex]++; // Place a gas station in this section
            long double newSectionLength = (arr[maxIndex+1] - arr[maxIndex]) / (long double)(howMany[maxIndex] + 1); // Calculate the new section length after placing the gas station
            pq.push({newSectionLength, maxIndex}); // Push the updated section length back into the heap
        }
        return pq.top().first; // Return the maximum section length
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 6;
    long double result = solution.minimiseMaxDistance(arr, k);
    cout << "Minimized maximum distance: " << result << endl;
    return 0;
}