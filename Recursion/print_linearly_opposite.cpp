// Print in terms of N to 1 means opposite

#include <iostream>   // input/output
#include <vector>     // dynamic arrays
#include <algorithm>  // sort, max, etc.
using namespace std;

// void oop_linearly(int i, int n){
//     if(i > n) return;

//     cout << n << endl;

//     oop_linearly(i, n-1);
// }

// int main(){
//     int n;
//     cin >> n;
//     oop_linearly(1,n);

// }

void oop_linearly(int i, int n){
    if(i < 1) return;

    cout << i << endl;

    oop_linearly(i-1, n);
}

int main(){
    int n;
    cin >> n;
    oop_linearly(n,n);

}