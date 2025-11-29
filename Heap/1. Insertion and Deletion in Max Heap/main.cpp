// Implementing Heap (insertion)

#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
    int *arr;
    int size;
    int total_size;

    public:

    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value) {
        if(size == total_size) {
            cout << "Heap Overflow" << endl;
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while(index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted into the heap" << endl;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.print();
    H1.insert(114);
    H1.insert(24);
    H1.insert(1);
    H1.insert(10);
    H1.print();
}

// output:
// 4 is inserted into the heap
// 14 is inserted into the heap
// 11 is inserted into the heap
// 14 4 11 
// 114 is inserted into the heap
// 24 is inserted into the heap
// 1 is inserted into the heap
// Heap Overflow
// 114 24 11 4 14 1 
// ............................................................................................
// Implementing Heap (Deletion)

#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
    int *arr;
    int size;
    int total_size;

    public:

    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value) {
        if(size == total_size) {
            cout << "Heap Overflow" << endl;
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while(index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted into the heap" << endl;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void Heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if(right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if(largest != index) {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }

    void Delete() {
        if(size == 0) {
            cout << "Heap Underflow" << endl;
            return;
        }

        cout << arr[0] << " deleted from the heap" << endl;
        arr[0] = arr[size - 1];
        size--;

        if(size == 0) {
            return; 
        }

        Heapify(0);
    }
};

int main() {
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.Delete();
    H1.print();
    H1.insert(114);
    H1.insert(24);
    H1.insert(1);
    H1.insert(10);
    H1.print();
    H1.Delete();
    H1.Delete();
    H1.Delete();
    H1.print();
    H1.Delete();
    H1.Delete();
    H1.Delete();
    H1.print();
    H1.Delete();
}

// output:
// 4 is inserted into the heap
// 14 is inserted into the heap
// 11 is inserted into the heap
// 14 deleted from the heap
// 11 4 
// 114 is inserted into the heap
// 24 is inserted into the heap
// 1 is inserted into the heap
// 10 is inserted into the heap
// 114 24 11 4 1 10 
// 114 deleted from the heap
// 24 deleted from the heap
// 11 deleted from the heap
// 10 4 1 
// 10 deleted from the heap
// 4 deleted from the heap
// 1 deleted from the heap

// Heap Underflow