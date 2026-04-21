#include <iostream>   // input/output
#include <vector>     // dynamic arrays
#include <algorithm>  // sort, max, etc.
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> aryan;
	
	for(int i = 1; i*i <= n; i++){
	    
	    if((n % i) == 0){
	        aryan.push_back(i);
	        
	        if((n / i) != i){
	            aryan.push_back(n/i);
	        }
	    }
	}
	
	sort(aryan.begin(), aryan.end());
	for(auto it : aryan) cout << it << " ";
}
