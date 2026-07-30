// Problem: Number of subarrays with XOR equal to K optimal
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach: We can use a hashmap to store the frequency of prefix XORs. We iterate through the array and calculate the current prefix XOR. For each prefix XOR, we check if there exists a previous prefix XOR such that their XOR is equal to K. If it does, we add the frequency of that previous prefix XOR to our count. Finally, we return the count.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

class Solution {
    public:
    int subarraysWithSumK(vector<int> a, int k){
        int xr = 0;
        map<int, int> mpp;
        mpp[xr]++; // {0, 1} -> 0 xor 0 = 0
        int cnt = 0;

        for(int i = 0; i < a.size(); i++){
            xr = xr ^ a[i]; // current xor
            // k
            int x = xr ^ k; // required xor
            cnt += mpp[x]; // if x is present in map, then add its frequency to count
            mpp[xr]++; // add current xor to map

        }
        return cnt;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    int result = solution.subarraysWithSumK(arr, k);
    cout << "Number of subarrays with XOR equal to " << k << ": " << result << endl;
    return 0;
}