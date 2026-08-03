// Problem: Find the missing and repeating numbers in an array Better Approach
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach:
// 1. Create a hash array of size n+1 initialized to 0.
// 2. Iterate through the input array and increment the count in the hash array for each number.
// 3. Iterate through the hash array to find the repeating and missing numbers.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
    vector<int> findMissingRepeatingNumbers(vector<int> a){
        int n = a.size();
        int repeating = -1, missing = -1;

        vector<int> hash(n + 1, 0);

        for(int i = 0; i < n; i++){
            hash[a[i]]++;
        }

        for(int j = 1; j <= n; j++){
            if(hash[j] == 2){
                repeating = j;
            }
            else if(hash[j] == 0){
                missing = j;
            }
        }

        return {repeating, missing};
    }
};    

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution solution;
    vector<int> result = solution.findMissingRepeatingNumbers(arr);

    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}