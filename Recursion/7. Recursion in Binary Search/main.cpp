// linear search

#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int x, int idx, int n) {
    // base case
    if(idx == n) {
        return 0;
    }

    if(arr[idx] == x) {
        return 1;
    }

    return linearSearch(arr, x, idx + 1, n);
}

int main() {
    int arr[] = {2, 3, 6, 7, 1, 5};
    int x = 22;
    cout << linearSearch(arr, x, 0, 6) << endl;
}

// output:
// 0
// ............................................................................................
// binary search

#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int start, int end, int x) {
    // base case
    if(start > end) {
        return 0;
    }

    int mid = start + (end - start) / 2;

    if(arr[mid] == x) {
        return 1;
    } else if(arr[mid] < x) {
        return binarySearch(arr, mid + 1, end, x);
    } else {
        return binarySearch(arr, start, mid - 1, x);
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int x = 13;
    cout << binarySearch(arr, 0, 5, x) << endl;
}

// output:
// 0