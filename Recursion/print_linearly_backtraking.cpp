#include <iostream>   // input/output
#include <vector>     // dynamic arrays
#include <algorithm>  // sort, max, etc.
using namespace std;

void backtracking(int i, int n){
    if(i < 1) return;

    backtracking(i-1, n);
    cout << i << endl;
}

int main(){
    int n;
    cin >> n;
    backtracking(n,n);
}