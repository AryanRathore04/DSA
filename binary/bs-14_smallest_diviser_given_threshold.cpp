// Problem: Given an array of integers and a threshold, find the smallest divisor such that the sum of the ceiling of each element divided by the divisor is less than or equal to the threshold.

// Time Complexity: O(n log(max)), where n is the size of the array and max is the maximum value in the array.
// Space Complexity: O(1)

// Approach: 1. Use binary search to find the smallest divisor. The search space is between 1 and the maximum value in the array.
// 2. For each mid value (potential divisor), calculate the sum of the ceiling of each element divided by mid.
// 3. If the sum is greater than the threshold, it means the divisor is too small, so we need to increase the divisor (low = mid + 1). If the sum is less than or equal to the threshold, we can try to find a smaller divisor (high = mid - 1).
// 4. Continue the binary search until low exceeds high, and return the low value, which will be the smallest divisor that satisfies the condition.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int smallestDivisor(vector<int>& arr, int limit){
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long sum = 0;

            for(int i = 0; i < arr.size(); i++){
                sum += (arr[i] + mid - 1) / mid; // Calculate the sum of the ceiling of arr[i] / mid
            }

            if(sum > limit){
                low = mid + 1; // Increase the divisor
            } else {
                high = mid - 1; // Decrease the divisor
            }
        }
        return low;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 5, 9};
    int limit = 6;
    int result = solution.smallestDivisor(arr, limit);
    cout << "The smallest divisor is: " << result << endl; // Output: The smallest divisor is: 5
    return 0;
}