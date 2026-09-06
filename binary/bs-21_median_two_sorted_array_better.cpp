// Problem: Find the median of two sorted arrays Better Approach
// Time Complexity: O(n1 + n2)
// Space Complexity: O(1)

// Approach: 1. Initialize n1 and n2 as the sizes of the two arrays a and b respectively.
// 2. Initialize two pointers i and j to 0, which will be used to traverse the two arrays.
// 3. Calculate the total number of elements n in both arrays and determine the indices of the median elements ind1 and ind2 based on whether n is odd or even.
// 4. Initialize a counter cnt to keep track of the number of elements processed and two variables ind1el and ind2el to store the values of the median elements.
// 5. Use a while loop to traverse both arrays simultaneously until one of the pointers reaches the end of its respective array.
// 6. Inside the loop, compare the current elements of both arrays and update the median element variables ind1el and ind2el based on the value of cnt. Increment the appropriate pointer and cnt accordingly.
// 7. After the first while loop, use two additional while loops to process any remaining elements in either array, updating the median element variables as needed.
// 8. Finally, check if the total number of elements n is odd or even. If n is odd, return the value of ind2el as the median. If n is even, return the average of ind1el and ind2el as the median.
// 9. The function returns the median value as a double.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    double median(vector<int>& a, vector<int>& b){
        int n1 = a.size();
        int n2 = b.size();
        int i = 0, j = 0;
        int n = n1 + n2;
        int ind2 = n / 2;
        int ind1 = ind2 - 1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;

        while (i < n1 && j < n2){
            if(a[i] < b[j]){
                if (cnt == ind1) ind1el = a[i];
                if (cnt == ind2) ind2el = a[i];
                cnt++;
                i++;
            } else {
                if (cnt == ind1) ind1el = b[j];
                if (cnt == ind2) ind2el = b[j];
                cnt++;
                j++;
            }
        }

        while (i < n1){
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }

        while (j < n2){
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }

        if(n % 2 == 1) return ind2el;

        return (double)((double)(ind1el + ind2el)) / 2.0;
    }
};

int main(){
    Solution s;
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout << s.median(a, b) << endl; // Output: 2.0

    vector<int> c = {1, 2};
    vector<int> d = {3, 4};
    cout << s.median(c, d) << endl; // Output: 2.5

    return 0;
}