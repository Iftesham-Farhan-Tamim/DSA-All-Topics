#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[1000];
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the element in array: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=1; i<n; i++) {
        for(int j=i; j>0; j--) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            } else {
                break;
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

// input:
// Enter the size of array: 6
// Enter the element in array: 6 5 4 3 2 1

// output:
// 1 2 3 4 5 6