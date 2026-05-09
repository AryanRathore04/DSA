#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int arr[], int low, int high){

    if(low >= high) return; // This stops recursion when the array has 1 element

    int mid = (low + high) / 2; // This divide the array into two parts

    mergeSort(arr, low, mid); // This sort left

    mergeSort(arr, mid+1, high); // This sort right

    merge(arr, low, mid, high); //After sorting this merge both side array

}


void merge(int arr[], int low, int mid, int high){

    //Now i need one temporary array and two pointers

    vector<int> temp;

    int left = low; // This pointer for left half
    int right = mid + 1; // This pointer for right half

    while(left <= mid && right <= high){ // This while is for until one side is finishes

        if(arr[left] <= arr[right]){ // This selects smaller one
            temp.push_back(arr[left]); // This put into temp array
            left++;
        }

        else{
            temp.push_back(arr[right]); // This put into temp array
            right++;
        }

    }

    // If elements still remain in left half
    while (left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    //If elements still remain in right half
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    //Copy sorted elements back to origianal array
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    // Input array
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Call merge sort
    mergeSort(arr, 0, n-1);

    // Print sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;

}