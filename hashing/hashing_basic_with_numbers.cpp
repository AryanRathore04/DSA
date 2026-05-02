// Counts frequency of numbers and answers queries instantly using an array

// arr[1e6] -----> only if inside main declare
// arr[1e7] or arr[1e7 + 1]  ------- globally declare

#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //precompute
    int hash[13] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }


    int q;
    cin >> q; // total number of queries
    while(q--){
        int number; // what are the queries
        cin >> number;
        //fetch
        cout << hash[number] << endl;
    }
    return 0;
}