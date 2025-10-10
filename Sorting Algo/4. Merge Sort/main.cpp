// Sort an Array (https://leetcode.com/problems/sort-an-array/description/)

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    vector<int>temp(end-start+1);
    int left = start, right = mid + 1, index = 0;

    while(left <= mid && right <= end) {
        if(arr[left] <= arr[right]) {
            temp[index] = arr[left];
            index++;
            left++;
        } else {
            temp[index] = arr[right];
            index++;
            right++;
        }
    }

    // left array is not empty yet
    while (left <= mid) {
        temp[index] = arr[left];
        index++;
        left++;
    }

    // right array is not empty yet
    while(right <= end) {
        temp[index] = arr[right];
        index++; 
        right++;
    }

    index = 0;
    while(start <= end) {
        arr[start] = temp[index];
        start++;
        index++;
    }
}

void mergeSort(int arr[], int start, int end) {
    // base case
    if(start == end) {
        return;
    }

    int mid = start + (end - start) / 2;
    // left side
    mergeSort(arr, start, mid);
    // right side
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main() {
    int arr[] = {6, 3, 1, 2, 8, 9, 10, 7, 3, 10};
    mergeSort(arr, 0, 9);
    for(int i=0; i<10; i++) {
        cout << arr[i] << " ";
    }
}

// output:
// 1 2 3 3 6 7 8 9 10 10