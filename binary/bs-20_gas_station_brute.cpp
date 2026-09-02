// Problem: Given an array of integers representing the positions of existing gas stations along a straight road, and an integer k representing the number of additional gas stations to be placed, the task is to minimize the maximum distance between any two adjacent gas stations after placing the k additional gas stations.
// Time Complexity: O(n*k), where n is the number of existing gas stations and k is the number of additional gas stations to be placed. This is because for each of the k gas stations, we iterate through the n-1 sections to find the section with the maximum length.
// Space Complexity: O(n), where n is the number of existing gas stations. We use an additional vector of size n-1 to keep track of how many gas stations are placed between each pair of existing stations.

// Approach: 1. Create a vector to keep track of how many gas stations are placed between each pair of existing stations.
// 2. For each of the k gas stations to be placed, find the section with the maximum length and place a gas station there. This is done by iterating through each pair of existing stations and calculating the length of the section if we place a gas station there. We keep track of the maximum section length and its index, and after iterating through all sections, we place a gas station in the section with the maximum length.
// 3. After placing all k gas stations, we iterate through each pair of existing stations again and calculate the length of the section after placing gas stations. We keep track of the maximum section length and return it as the minimized maximum distance between gas stations.
// 4. The algorithm uses a greedy approach to place the gas stations in the sections with the maximum length, which ensures that the maximum distance between any two adjacent gas stations is minimized.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    long double minimiseMaxDistance(vector<int> &arr, int k){
        int n = arr.size();
        // Create a vector to keep track of how many gas stations are placed between each pair of existing stations
        vector<int> howMany(n-1, 0);
        // Place k gas stations in a greedy manner
        for(int gasStation = 1; gasStation <= k; gasStation++){
            // Find the section with the maximum length and place a gas station there
            long double maxSection = -1; // Initialize the maximum section length to a very small value
            int maxIndex = -1; // Initialize the index of the maximum section to -1
            for(int i = 0; i < n-1; i++){ // Iterate through each pair of existing stations
                long double diff = (arr[i+1] - arr[i]); // Calculate the distance between the current pair of stations
                long double sectionLength = diff / (howMany[i] + 1); // Calculate the length of the section if we place a gas station here
                if(sectionLength > maxSection){ // If this section length is greater than the current maximum section length
                    maxSection = sectionLength; // Update the maximum section length
                    maxIndex = i; // Update the index of the maximum section
                }
            }
            howMany[maxIndex]++; // Place a gas station in the section with the maximum length
        }

        long double maxAns = -1; // Initialize the maximum answer to a very small value
        for(int i = 0; i < n-1; i++){ // Iterate through each pair of existing stations
            long double diff = (arr[i+1] - arr[i]); // Calculate the distance between the current pair of stations
            long double sectionLength = diff / (howMany[i] + 1); // Calculate the length of the section after placing gas stations
            maxAns = max(maxAns, sectionLength); // Update the maximum answer if this section length is greater than the current maximum answer
        }
        return maxAns; // Return the maximum answer, which is the minimized maximum distance between gas stations
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