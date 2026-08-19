// Leetcode 744. Find Smallest Letter Greater Than Target
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach: The binary search algorithm is used to find the smallest letter greater than the target value in a sorted array of letters. The algorithm maintains two pointers, low and high, which represent the current search space. In each iteration, the middle index is calculated and compared with the target value. If the middle letter is greater than the target, it is stored as a potential answer, and the search continues in the left half of the array. If the middle letter is less than or equal to the target, the search continues in the right half of the array. This process continues until the search space is exhausted. Finally, the answer representing the smallest letter greater than the target is returned.

#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;
        char ans = letters[0];

        while(low <= high){
            int mid = (low + high) / 2;

            if(letters[mid] > target){
                ans = letters[mid];
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};