#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m){
    int i = 0;
    int j = 0;

    vector<int> ans;

    while(i < n && j < m){
        if(A[i] < B[j]){
            i++;
        }

        else if(B[j] < A[i]){
            j++;
        }

        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<int> A(n);
    vector<int> B(m);

    for(int i = 0; i < n; i++){
        cin  >> A[i];
    }

    for(int i = 0; i < m; i++){
        cin >> B[i];
    }

   vector<int> result = findArrayIntersection(A, n, B, m);

   for(auto it : result){
    cout << it << " ";
   }

    return 0;
}