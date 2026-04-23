// Print Linearly from 1 to N

#include <iostream>   // input/output
#include <vector>     // dynamic arrays
#include <algorithm>  // sort, max, etc.
using namespace std;

void linearly(int i, int n){
    if(i > n) return;

    cout << i << endl;

    linearly(i+1, n);
}

int main(){
    int n;
    cin >> n;
    linearly(1,n);
}