// Find the second largest number

#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
#include <climits> 
using namespace std;

int largestNumber(vector<int> &arr, int n){
    int largest = INT_MIN;
    int sLargest = INT_MIN;
    for(int i = 0; i < n; i++){
       if(arr[i] > largest){
        sLargest = largest;
        largest = arr[i];
       }

       else if(arr[i] > sLargest && arr[i] != largest){
        sLargest = arr[i];
       }
    }

    return sLargest;

}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sLargest = largestNumber(arr, n);

    cout << sLargest;

    return 0;
}