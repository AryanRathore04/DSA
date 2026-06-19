// Check if the array is sorted 

 
#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
#include <climits> 
using namespace std;

int isSorted(vector<int> &arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]){

        }
        else{
            return false;
        }
    } 
    return true;  
}


int main(){

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }

    isSorted(arr, n);

    bool ans = isSorted(arr, n);

    cout << boolalpha << ans;


    return 0;
}