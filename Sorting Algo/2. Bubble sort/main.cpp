// Bubble sort (https://www.geeksforgeeks.org/problems/bubble-sort/1)

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

    for(int i = n - 2; i >= 0; i--) {
        bool swapped = 0;
        for(int j = 0; j <= i; j++) {
            if(arr[j] > arr[j + 1]) {
                swapped = 1;
                swap(arr[j], arr[j + 1]);
            }
        }

        if(swapped == 0) {
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// input:
// Enter the size of array: 8
// Enter the element in array: 8 7 6 5 4 3 2 1

// output:
// 1 2 3 4 5 6 7 8