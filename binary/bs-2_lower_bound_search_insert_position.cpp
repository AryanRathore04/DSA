#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int lowerBound(vector<int>& nums, int n, int x){
        int low = 0;
        int high = nums.size() - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int result = solution.lowerBound(nums, nums.size(), target);
    cout << "The lower bound index of " << target << " is: " << result << endl;
    return 0;
}