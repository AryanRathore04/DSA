// Leetcode 556. Next Greater Element III
// Time Complexity: O(N)
// Space Complexity: O(N)

// Approach: The idea is to find the next greater permutation of the digits of the number. We can do this by following these steps:
// 1. Convert the number to a vector of digits.
// 2. Find the first digit that is smaller than the digit next to it, from the right. Let's call this digit 'pivot'.
// 3. If no such digit is found, it means the digits are in descending order, and we cannot find a greater number. Return -1.
// 4. If a pivot is found, find the smallest digit on the right side of the pivot that is greater than the pivot. Let's call this digit 'successor'.
// 5. Swap the pivot and successor.
// 6. Reverse the digits to the right of the pivot's original position to get the next greater permutation.
// 7. Convert the vector of digits back to an integer and check if it exceeds the 32-bit signed integer limit. If it does, return -1. Otherwise, return the integer. 

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        int ind = -1;
        int a = digits.size();
        for (int i = a - 2; i >= 0; i--) {
            if (digits[i] < digits[i + 1]) {
                ind = i;
                break;
            }
        }

        if (ind == -1) {
            return -1;
        }

        for (int i = a - 1; i > ind; i--) {
            if (digits[i] > digits[ind]) {
                swap(digits[i], digits[ind]);
                break;
            }
        }

        reverse(digits.begin() + ind + 1, digits.end());

        long long num = 0;

        for (int digit : digits) {
            num = num * 10 + digit;
        }

        if(num > INT_MAX){
            return -1;
        }

        return num;
    }
};