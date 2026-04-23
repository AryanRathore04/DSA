// Sum of first N numbers in two ways parameter and functional

#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
using namespace std;


//PARAMERTERISED
// void paramerterised(int i, int sum)
// {
//     if (i < 1)
//     {
//         cout << sum;
//         return;
//     }

//     paramerterised(i-1, sum + i);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     paramerterised(n,0);
// }



//FUNCTIONAL

int sum(int n){
    if(n == 0) return 0;
    return n + sum(n-1);

}

int main(){
    int n;
    cin >> n;
    cout << sum(n);

    return 0;

}
