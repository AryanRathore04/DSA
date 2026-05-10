// Remove the duplicated number from the array
 
#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
using namespace std;

int removeDuplicates(vector<int> &arr, int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

   int ans = removeDuplicates(arr, n);
   cout << ans << endl;
    for(int i = 0; i < ans; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}