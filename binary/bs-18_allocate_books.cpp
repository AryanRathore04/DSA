// Problem: Allocate minimum number of pages
// Time Complexity: O(n log(sum of pages))
// Space Complexity: O(1)

// Approach: 1. initialize low as the maximum number of pages in a single book and high as the sum of all pages.
// 2. Use binary search to find the minimum number of pages that can be allocated to m students.
// 3. For each mid value, count the number of students required to allocate the books such that no student gets more than mid pages.
// 4. If the number of students required is more than m, it means we need to increase the number of pages allocated to each student, so we set low = mid + 1.
// 5. If the number of students required is less than or equal to m, it means we can try to allocate fewer pages, so we set high = mid - 1.
// 6. Finally, return low as the minimum number of pages that can be allocated to m students.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
    public:
    int countStudents(vector<int> &arr, int pages){
        int students = 1;
        long long pagesStudents = 0;

        for(int i = 0; i < arr.size(); i++){
            if(pagesStudents + arr[i] <= pages){
                pagesStudents += arr[i];
            }
            else{
                students += 1;
                pagesStudents = arr[i];
            }
        }
        return students;;
    }

    int findPages(vector<int>& arr, int n, int m){
        if(m > n) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;
            int students = countStudents(arr, mid);

            if(students > m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low;
    }
};

int main() {
    int n = 4;
    int m = 2;

    vector<int> arr = {12, 34, 67, 90};

    Solution solution;
    int result = solution.findPages(arr, n, m);

    cout << result << endl;

    return 0;
}