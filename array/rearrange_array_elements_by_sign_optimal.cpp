// Problem: Rearrange Array Elements by Sign Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach:
// 1. Create a new vector 'ans' of the same size as the input array, initialized with zeros.
// 2. Use two pointers, 'posIndex' starting at 0 for positive numbers and 'negIndex' starting at 1 for negative numbers.
// 3. Iterate through the input array 'nums': 
//   - If the current number is negative, place it at 'negIndex' in 'ans' and increment 'negIndex' by 2.
//   - If the current number is positive, place it at 'posIndex' in 'ans' and increment 'posIndex' by 2.
// 4. Return the rearranged array 'ans'.


#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> rearrangeArray(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};

// Problem: Rearrange Array Elements by Sign Bruteforce Solution where the number of positive and negative numbers may not be equal
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach:
// 1. Create two separate vectors 'pos' and 'neg' to store positive and negative numbers from the input array 'a'.
// 2. Iterate through the input array 'a' and populate 'pos' with positive numbers and 'neg' with negative numbers.
// 3. Check the sizes of 'pos' and 'neg':
//   - If 'pos' has more elements than 'neg', fill the input array 'a' by alternating elements from 'pos' and 'neg', starting with a positive number. After exhausting the negative numbers, fill the remaining positions in 'a' with the remaining positive numbers.
//   - If 'neg' has more elements than 'pos', fill the input array 'a' by alternating elements from 'pos' and 'neg', starting with a positive number. After exhausting the positive numbers, fill the remaining positions in 'a' with the remaining negative numbers.
// 4. Return the rearranged array 'a'.
class Solution {
    public:
    vector<int> alternateNumbers(vector<int>& a){
        vector<int> pos, neg;
        int n = a.size();

        for(int i = 0; i < n; i++){
            if(a[i] > 0){
                pos.push_back(a[i]);
            }
            else{
                neg.push_back(a[i]);
            }
        }

        if(pos.size() > neg.size()){
            for(int i = 0; i < neg.size(); i++){
                a[2 * i] = pos[i];
                a[2 * i + 1] = neg[i];
            }
            int index = neg.size() * 2;
            for (int i = neg.size(); i < pos.size(); i++){
                a[index] = pos[i];
                index++;
            }
            
        }
        else{
            for(int i = 0; i < pos.size(); i++){
                a[2 * i] = pos[i];
                a[2 * i + 1] = neg[i];
            }

            int index = pos.size() * 2;
            for (int i = pos.size(); i < neg.size(); i++){
                a[index] = neg[i];
                index++;
            }
        }

        return a;
    }
};