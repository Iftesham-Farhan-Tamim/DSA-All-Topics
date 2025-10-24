// print array

#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int idx, int n) {
    if(idx == n) {
        return;
    }

    cout << arr[idx] << " ";
    print(arr, idx + 1, n);
}

int main() {
    int arr[] = {3, 4, 1, 2, 8};
    print(arr, 0, 5);
}

// output:
// 3 4 1 2 8
// ............................................................................................
// print array

#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int idx) {
    cout << arr[idx] << " ";
}

int main() {
    int arr[] = {3, 4, 1, 2, 8};
    for(int i = 0; i < 5; i++) {
        print(arr, i);
    }
}

// output:
// 3 4 1 2 8
// ............................................................................................
// print array

#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int idx) {
    if(idx == -1) {
        return;
    }

    cout << arr[idx] << " ";
    print(arr, idx - 1);
}

int main() {
    int arr[] = {3, 4, 1, 2, 8};
    print(arr, 4);
}

// output:
// 8 2 1 4 3
// ............................................................................................
// sum of all element

#include<bits/stdc++.h>
using namespace std;

int sum(int arr[], int idx, int n) {
    if(idx == n) {
        return 0;
    }

    return arr[idx] + sum(arr, idx + 1, n);
}

int main() {
    int arr[] = {3, 4, 1, 2, 8};
    cout << sum(arr, 0, 5) << endl;
}

// output:
// 18
// ............................................................................................
// find the min element

#include<bits/stdc++.h>
using namespace std;

int minElement(int arr[], int idx) {
    return arr[idx];
}

int main() {
    int arr[] = {3, 4, 1, 2, 8};
    int num = arr[0];

    for(int i = 0; i < 5; i++) {
        num = min(num, minElement(arr, i));
    }

    cout << num << endl;
}

// output:
// 1
// ............................................................................................
// find the min element

#include<bits/stdc++.h>
using namespace std;

int minElement(int arr[], int idx, int n) {
    if(idx == n - 1) {
        return arr[idx];
    }

    return min(arr[idx], minElement(arr, idx + 1, n));
}

int main() {
    int arr[] = {3, 4, 1, 2, 8};
    
    cout << minElement(arr, 0, 5) << endl;
}

// output:
// 1