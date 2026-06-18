// Find the number that appears once and other twice by the XOR method

#include <iostream>
#include <vector>
using namespace std;

int SingleNumber(vector<int> &arr, int n){
    int xor1 = 0;

    for(int i = 0; i < n; i++){
        xor1 = xor1 ^ arr[i];
    }

    return xor1;

}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = SingleNumber(arr, n);

    cout << ans;
}