// Left Rotate the array by D positions;

#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
using namespace std;

void leftRotateByD(int arr[], int n, int d){
   d = d % n;

   int temp[d];
   // This loop is for taking elements from 0 to dth position
   for(int i = 0; i < d; i++){ 
    temp[i] = arr[i];
   }

   // This loop is for shifting the element from dth to nth to the staring
   for(int i = d; i < n; i++){
    arr[i - d] = arr[i];
   }

   //This loop is for filling the empty last digits from the first
   for(int i = n - d; i < n; i++){
    arr[i] = temp[i - (n - d)];
   }
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

    leftRotateByD(arr, n, d);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}