// This code demonstrates a simple hashing technique to count the frequency of each number in a given array. It uses a map to store the count of each integer. The program first precomputes the frequency of each integer in the input array and then answers queries about the frequency of specific integers in constant time O(1).

#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
#include <map>       // adding map
using namespace std;

int main(){

    int n; // size of the array
    cin >> n;  // input size of the array
    int arr[n]; // declare the array of size n
    for (int i = 0; i < n; i++){ // input the array
        cin >> arr[i]; // input the elements of the array
    }
   
    // Precompute
    map<int, int> mpp; // create a map to store the frequency of each integer
    for (int i = 0; i < n; i++){ // iterate through the array and update the frequency of each integer in the map
        mpp[arr[i]]++; // increment the frequency of the integer in the map
    }


    int q; // number of queries
    cin >> q; // input the number of queries
    while(q--){ // iterate through the queries
        int number; // variable to store the query number
        cin >> number; // input the query number
        //fetch
        cout << mpp[number] << endl; // output the frequency of the query number from the map
    }

    return 0; // return 0 to indicate successful execution of the program
}