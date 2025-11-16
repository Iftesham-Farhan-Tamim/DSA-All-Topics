// print and find element in 2d array

#include<bits/stdc++.h>
using namespace std;

void printCol(int arr[][4], int row, int col) {
    for(int j = 0; j < col; j++) {
        for(int i = 0; i < row; i++) {
            cout << arr[i][j] << " ";
        }
    }

    cout << endl;
}

int main() {
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 4; col++) {
            cout << arr[row][col] << " ";
        }
    }

    printCol(arr, 3, 4);

    int x = 7;

    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 4; col++) {
            if(arr[row][col] == x) {
                cout << "Yes " << endl;
                return 0;
            }
        }
    }

    cout << "No " << endl;
}

// output:
// 1 2 3 4 5 6 7 8 9 10 11 12 1 5 9 2 6 10 3 7 11 4 8 12 
// Yes
// ............................................................................................
// Add 2 matrix

#include<bits/stdc++.h>
using namespace std;

void printCol(int arr[][4], int row, int col) {
    for(int j = 0; j < col; j++) {
        for(int i = 0; i < row; i++) {
            cout << arr[i][j] << " ";
        }
    }

    cout << endl;
}

int main() {
    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[3][4] = {0, 1, 3, 4, 6, 7, 10, 11, 41, 18, 9, 11};
    int ans[3][4];

    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 4; col++) {
            ans[row][col] = arr1[row][col] + arr2[row][col];
        }
    }

    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 4; col++) {
            cout << ans[row][col] << " ";
        }
    }
}

// output:
// 1 3 6 8 11 13 17 19 50 28 20 23
// ............................................................................................
// Print row index with max sum

#include <bits/stdc++.h>
using namespace std;

void printrowmax(int arr[][4], int row, int col) {
    int index = -1, sum = INT_MIN;

    for(int i = 0; i < row; i++) {
        int total = 0;
        for(int j = 0; j < col; j++) {
            total += arr[i][j];

            if(total > sum) {
                sum = total;
                index = i;
            }
        }
    }

    cout << index << " ";
}

int main() {
    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[3][4] = {0, 1, 3, 4, 6, 7, 10, 11, 41, 18, 9, 11};

    printrowmax(arr1, 3, 4); 
    printrowmax(arr2, 3, 4);
}

// output:
// 2 2
// ............................................................................................
// print sum of diagonal element

#include <bits/stdc++.h>
using namespace std;

void printsumdig(int matrix[][3], int row, int col) {
    int first = 0;
    int sec = 0;

    // first diagnonal sum
    int i = 0;
    while(i < row) {
        first += matrix[i][i];
        i++;
    }

    // second diagnonal
    i = 0;
    int j = col - 1;

    while(j >= 0) {
        sec += matrix[i][j];
        i++;
        j--;
    }

    cout << first << " " << sec << " ";
}

int main() {
    int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printsumdig(matrix, 3, 3);
}

// output:
// 15 15
// ............................................................................................
// Reverse each row of matrix


// ............................................................................................
