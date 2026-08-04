#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        vector<int> temp(right - left + 1);
        int i = left, k = 0;
        j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (int i = left; i <= right; i++) {
            nums[i] = temp[i - left];
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += mergeAndCount(nums, left, mid, right);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {40, 25, 19, 12, 9, 6, 2};
    int result = solution.reversePairs(nums);
    cout << "Number of reverse pairs: " << result << endl;
    return 0;
}