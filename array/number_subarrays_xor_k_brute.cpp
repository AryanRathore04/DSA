// Problem: Number of subarrays with XOR equal to K brute force
// Time Complexity: O(n^3)
// Space Complexity: O(1)

// Approach: We can use three nested loops to generate all possible subarrays of the given array. For each subarray, we calculate the XOR of its elements and check if it is equal to K. If it is, we increment the count of such subarrays. Finally, we return the count.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int subarraysXorK(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int XOR = 0;
                for(int k = i; k <= j; k++){
                    XOR ^= arr[k];
                }
                if(XOR == k){
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    int result = solution.subarraysXorK(arr, k);
    cout << "Number of subarrays with XOR equal to " << k << ": " << result << endl;
    return 0;
}