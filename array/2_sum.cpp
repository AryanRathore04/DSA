// Sam want to read exactly 'TARGET' number of pages. He has an array 'BOOK' containing the number of pages for 'N' books. Return YES/NO, if it is possible for him to read any 2 books and he can meet his 'TARGET' number of pages.

// Example: 
// Input: 'N' = 5, 'TARGET' = 5
// 'BOOK' = [4, 1, 2, 3, 1]

// Output: YES
// Explanation: Sam can buy 4 pages book and 1 page book.

// Approach: The optimal approach involves iterating through the input array while maintaining a map to track the number of pages in each book. For each book, we calculate the number of pages needed to reach the target and check if that number exists in the map. If it does, we return "YES". If we finish iterating through the array without finding a match, we return "NO".

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

string read(int n, vector<int> book, int target){
    map<int, int> mpp;
    for(int i = 0; i<n; i++){
        int a = book[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            return "YES";
        }
        mpp[a] = i;
    }
    return "NO";
}