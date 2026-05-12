// Left Rotate the array by D positions - Optimal approach;

#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
using namespace std;

void leftRotate(int arr[], int n, int d){
    reverse(arr, arr+d); // This reverse the array from 0 to dth index
    reverse(arr+d, arr+n); // This reverse the array from dth index to nth index
    reverse(arr, arr+n); // This reverse the array from 0th to nth index means fully
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int d;
    cin >> d;
    leftRotate(arr, n, d);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
    
}