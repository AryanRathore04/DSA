#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
#include <map>       // adding map
using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
   
    // Precompute
    map<int, int> mpp;
    for (int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }


    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        //fetch
        cout << mpp[number] << endl;
    }

    return 0;
}