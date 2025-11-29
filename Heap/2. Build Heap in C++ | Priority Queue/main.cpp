// Building Max Heap

#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int index, int n) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if(largest != index) {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

void BuildMaxHeap(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--){
        Heapify(arr, i, n);
    }
}

void printHeap(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    BuildMaxHeap(arr, 10);
    printHeap(arr, 10);
}

// output:
// 70 14 18 11 5 13 8 9 10 3 
// ............................................................................................
// Implementing Heap Sort

#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int index, int n) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if(largest != index) {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

void BuildMaxHeap(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--){
        Heapify(arr, i, n);
    }
}

void printHeap(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void sortArray(int arr[], int n) {
    for(int i = n - 1; i > 0; i--) {
        swap(arr[i], arr[0]);
        Heapify(arr, 0, i);
    }
}

int main() {
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    BuildMaxHeap(arr, 10);
    sortArray(arr, 10);
    printHeap(arr, 10);
}

// output:
// 3 5 8 9 10 11 13 14 18 70 
// ............................................................................................
// Priority Queue (Max-heap)

#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int>p;

    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);

    cout << p.top() << " ";

    // delete
    p.pop();
    cout << p.top() << " ";

    // size
    cout << p.size() << endl;

    while(!p.empty()) {
        cout << p.top() << " ";
        p.pop();
    }
}

// output:
// 20 18 4
// 18 15 11 10 
// ............................................................................................
// Priority Queue (Min-heap)

#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > p;

    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);

    cout << p.top() << endl;

    while(!p.empty()) {
        cout << p.top() << " ";
        p.pop();
    }
}

// output:
// 10
// 10 11 15 18 20