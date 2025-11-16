// Binary Search (https://leetcode.com/problems/binary-search/description/)

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    // start, end, mid
    int start = 0, end = n - 1, mid;

    while(start <= end) {
        // find the mid
        mid = start + (end - start) / 2;

        if(arr[mid] == key) {  // arr[mid] == key
            return mid;
        } else if(arr[mid] < key) {  // arr[mid] < key
            start = mid + 1;
        } else {  // arr[mid] > key
            end = mid - 1;
        }        
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int arr[1000];
    int n;
    cout << "Enter the number of element in array: ";
    cin >> n;
    cout << "Enter the element: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    cout << binarySearch(arr, n, key) << endl;
}

// input1:
// Enter the number of element in array: 6
// Enter the element: 2 4 5 8 10 12
// Enter the key: 10

// output2:
// 4

// input2:
// Enter the number of element in array: 7
// Enter the element: 2 3 4 7 8 10 12
// Enter the key: 14

// output2:
// -1