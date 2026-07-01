// Next Greater Permutation
// Time Complexity: O(3N)
// Space Complexity: O(1)

// Approach: We can find the next greater permutation by following these steps:
// 1. Traverse the array from the end to find the first decreasing element (let's call it A[ind]).
// 2. If no such element is found, reverse the entire array to get the smallest permutation.
// 3. If such an element is found, traverse the array from the end again to find the first element that is greater than A[ind] and swap them.
// 4. Finally, reverse the subarray from ind + 1 to the end of the array
// 5. Return the modified array as the next greater permutation.

#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> nextGreaterPermutation(vector<int> &A){
        int ind = -1;
        int n = A.size();

        // This loop is for to know the index which is the smallest from the previous one from the right to n-2 place.
        for(int i = n - 2; i >= 0; i--){
            if(A[i] < A[i + 1]){
                ind = i;
                break;
            }
        }

        // The edge case is if there is no break point or like not the smallest one from the previous one.
        if(ind == -1){
            reverse(A.begin(), A.end());
            return A;
        }

        // This is for get the smallest number between the n-1 to ind and then swap it with the ind.
        for(int i = n - 1; i > ind; i--){
            if(A[i] > A[ind]){
                swap(A[i], A[ind]);
                break;
            }
        }

        //Reverse the suffix because it is currently in descending order, and reversing makes it the smallest possible suffix, giving the immediate next permutation.
        reverse(A.begin() + ind + 1, A.end());
        return A;
    }
};