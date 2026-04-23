// Print Name N times using Recursion

#include <iostream>   // input/output
#include <vector>     // dynamic arrays
#include <algorithm>  // sort, max, etc.
using namespace std;

void f(int i,int n){
    if(i > n) return; // Base condition
    cout << "Aryan" << endl; // print name n times

    f(i + 1, n);
}

int main(){
    int n;
    cin >> n;
    f(1,n);
}