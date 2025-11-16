#include<bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
}

// input:
// 6
// 1 2 3 4 5 6

// output:
// 1 2 3 4 5 6