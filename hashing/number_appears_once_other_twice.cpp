// Find the number that appears once in an array where every other number appears twice.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findSingleNumber(vector<int> &arr, int n){
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(mpp[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = findSingleNumber(arr,  n);
    cout << ans;

}
