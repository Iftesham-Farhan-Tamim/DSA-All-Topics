#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end) {
    int pos = start;
    for(int i = start; i <= end; i++) {
        if(arr[i] <= arr[end]) {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }

    return pos - 1;
}

void quickSort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }

    int pivot = partition(arr, start, end);
    // left side
    quickSort(arr, start, pivot - 1);
    // right side
    quickSort(arr, pivot, end);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int arr[] = {10, 3, 4, 1, 5, 6, 3, 2, 11, 9};
    quickSort(arr, 0, 9);
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}

// output:
// 1 2 3 3 4 5 6 9 10 11