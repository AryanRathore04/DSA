// This code demonstrates a simple hashing technique to count the frequency of each alphabet in a given string. It uses an array of size 26 to store the count of each character (assuming only lowercase letters). The program first precomputes the frequency of each character in the input string and then answers queries about the frequency of specific characters in constant time O(1).


#include <iostream>  // input/output
#include <vector>    // dynamic arrays
#include <algorithm> // sort, max, etc.
using namespace std;

int main(){
    string s;
    cin >> s;

    //precompute
    int hash[26] = {0};
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a']++;
    }

    int q; //number of queries
    cin >> q;
    while(q--){
        char c; // what are the queries
        cin >> c;
        //fetch
        cout << hash[c-'a'] << endl;
    }
}