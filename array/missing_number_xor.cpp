// Find the missing number by the XOR method.

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>&arr, int N){
    int xor1 = 0;
    int xor2 = 0;
    int n = N-1;

    for(int i = 0; i < n; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;

    return xor1 ^ xor2;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int N = 0;

   int result = missingNumber(arr, N);

   cout << result;
}