// Problem: Given an array of integers representing positions of gas stations along a straight road, and an integer k representing the number of additional gas stations that can be added, the task is to minimize the maximum distance between any two adjacent gas stations after adding the k new gas stations.

// Time Complexity: O(n log n + k log n), where n is the number of existing gas stations and k is the number of additional gas stations to be placed. The initial sorting of the array takes O(n log n) time, and for each of the k gas stations, we perform a log n operation to maintain the max-heap.

// Space Complexity: O(n), where n is the number of existing gas stations. We use an additional vector of size n-1 to keep track of how many gas stations are placed between each pair of existing stations, and a max-heap to keep track of the maximum section lengths.

// Approach: 1. Initialize the search range for the maximum distance between gas stations. The lower bound is 0, and the upper bound is the maximum distance between any two existing gas stations.
// 2. Use binary search to find the minimum possible maximum distance. In each iteration, calculate the mid-point of the current search range and check if it is possible to place k additional gas stations such that the maximum distance between any two adjacent gas stations is less than or equal to mid.
// 3. To check if it is possible to place k additional gas stations, iterate through the existing gas stations and count how many additional gas stations are needed to ensure that the distance between any two adjacent gas stations is less than or equal to mid. If the count of additional gas stations needed is less than or equal to k, then it is possible to achieve the desired maximum distance.
// 4. If it is possible to achieve the desired maximum distance, update the upper bound of the search range to mid. Otherwise, update the lower bound to mid. Repeat this process until the search range converges to a sufficiently small value, which will be the minimized maximum distance between any two adjacent gas stations after adding the k new gas stations.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:

    // Returns how many additional gas stations
    // are required if the maximum allowed distance
    // between adjacent stations is maxDistance.
    int numberOfGasStations(vector<int>& arr, long double maxDistance) {

        int n = arr.size();

        int cnt = 0;

        for(int i = 0; i < n - 1; i++) {

            long double distance = arr[i + 1] - arr[i];

            int stationsNeeded =
                (int)ceil(distance / maxDistance) - 1;

            cnt += stationsNeeded;
        }

        return cnt;
    }


    long double minimiseMaxDistance(vector<int>& arr, int k) {

        int n = arr.size();

        // Smallest possible answer.
        long double low = 0.0;

        // Largest possible answer.
        long double high = 0.0;

        // Find the largest existing gap.
        for(int i = 0; i < n - 1; i++) {

            high = max(
                high,
                (long double)(arr[i + 1] - arr[i])
            );
        }


        // Required precision.
        long double diff = 1e-6;


        while(high - low > diff) {

            // Candidate answer.
            long double mid =
                low + (high - low) / 2.0;


            // How many stations would we need
            // to make every gap <= mid?
            int cnt =
                numberOfGasStations(arr, mid);


            // We need more than k stations.
            // Therefore mid is too small.
            if(cnt > k) {

                low = mid;
            }

            // We can achieve mid using k or fewer
            // stations.
            else {

                high = mid;
            }
        }


        // high is our best possible answer.
        return high;
    }
};


int main() {

    Solution solution;

    vector<int> arr = {
        1, 2, 3, 4, 5, 6, 7
    };

    int k = 6;

    long double result =
        solution.minimiseMaxDistance(arr, k);

    cout << "Minimum maximum distance: "
         << result << endl;

    return 0;
}