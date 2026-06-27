// Leetcode 169. Majority Element
// Time Complexity: O(N)
// Space Complexity: O(1)

//Explanation: The algorithm uses Boyer-Moore Majority Vote Algorithm. It maintains a count and an element. If the count is 0, it updates the element. If the current element is the same as the stored element, it increments the count; otherwise, it decrements the count. At the end, it returns the stored element as the majority element.

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = 0;

        for(int i = 0; i < nums.size(); i++){
            if(count  == 0){
                element = nums[i];
                count = 1;
            }
            else if(nums[i] == element){
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }
};