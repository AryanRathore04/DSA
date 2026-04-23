// Print linearly from N to 1 (But by Backtracking)


#include <iostream>   // input/output
#include <vector>     // dynamic arrays
#include <algorithm>  // sort, max, etc.
using namespace std;

void backtracking(int i, int n){
    if(i > n) return;

    backtracking(i+1, n);
    cout << i << endl;
}

int main(){
    int n;
    cin >> n;

    backtracking(1,n);

}