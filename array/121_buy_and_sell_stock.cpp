// Leetcode 121. Best Time to Buy and Sell Stock
// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach:
// 1. Initialize a variable 'mini' to the first element of the prices array, which represents the minimum price seen so far.
// 2. Initialize a variable 'maxProfit' to 0, which will store the maximum profit that can be achieved.
// 3. Iterate through the prices array starting from the second element.
// 4. For each price, calculate the potential profit by subtracting 'mini' from the current price.
// 5. Update 'maxProfit' if the potential profit is greater than the current 'maxProfit'.
// 6. Update 'mini' if the current price is less than 'mini'.
// 7. After iterating through the array, return 'maxProfit' as the result, which represents the maximum profit that can be achieved by buying and selling the stock once.

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);

            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};