// Problem: Given an array of integers representing positions of gas stations along a straight road, and an integer k representing the number of additional gas stations that can be added, the task is to minimize the maximum distance between any two adjacent gas stations after adding the k new gas stations.
// Time Complexity: O(n log n + k log n), where n is the number of existing gas stations and k is the number of additional gas stations to be placed. The initial sorting of the array takes O(n log n) time, and for each of the k gas stations, we perform a log n operation to maintain the max-heap.
// Space Complexity: O(n), where n is the number of existing gas stations. We use an additional vector of size n-1 to keep track of how many gas stations are placed between each pair of existing stations, and a max-heap to keep track of the maximum section lengths.
// Approach: 1. Create a max-heap (priority queue) to keep track of the maximum section lengths and their indices. 
// 2. For each of the k gas stations to be placed, extract the section with the maximum length from the heap, place a gas station there, and update the section length in the heap. 
// 3. After placing all k gas stations, the maximum section length in the heap will be the minimized maximum distance between any two adjacent gas stations. 
// 4. The algorithm uses a greedy approach to place the gas stations in the sections with the maximum length, which ensures that the maximum distance between any two adjacent gas stations is minimized.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    long double minimiseMaxDistance(vector<int>& arr, int k) {

        int n = arr.size();

        // howMany[i] tells us how many new gas stations
        // have been placed between arr[i] and arr[i+1]
        vector<int> howMany(n - 1, 0);

        // Max-heap:
        // first  = current maximum section length
        // second = index of the original gap
        priority_queue<pair<long double, int>> pq;


        // Put all original gaps into the max-heap
        for(int i = 0; i < n - 1; i++) {

            long double diff = arr[i + 1] - arr[i];

            pq.push({diff, i});
        }


        // Add k new gas stations
        for(int gasStation = 1; gasStation <= k; gasStation++) {

            // Get the largest current section
            auto tp = pq.top();

            // Remove it temporarily
            pq.pop();

            // tp.first  = current section length
            // tp.second = index of the original gap
            int maxIndex = tp.second;


            // Add one new gas station to this gap
            howMany[maxIndex]++;


            // Calculate the new maximum section
            // inside this original gap
            long double newSectionLength =
                (arr[maxIndex + 1] - arr[maxIndex])
                / (long double)(howMany[maxIndex] + 1);


            // Put the updated section back into the heap
            pq.push({newSectionLength, maxIndex});
        }


        // The largest remaining section is at the top
        return pq.top().first;
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