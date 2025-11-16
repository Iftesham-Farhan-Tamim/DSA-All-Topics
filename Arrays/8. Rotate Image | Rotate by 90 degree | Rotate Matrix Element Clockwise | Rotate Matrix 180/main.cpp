// Rotate Image (https://leetcode.com/problems/rotate-image/description/)

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Transpose
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for(int i = 0; i < n; i++) {
        int start = 0, end = n - 1;
        while(start <= end) {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate(matrix);

    cout << "Rotated Matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// output:
// Rotated Matrix:
// 7 4 1 
// 8 5 2 
// 9 6 3 
// ............................................................................................
// Rotate a Matrix by 180 Counterclockwise (https://www.geeksforgeeks.org/problems/c-matrix-rotation-by-180-degree0745/1?utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for(int j = 0; j < n; j++) {
        // column wise reverse
        int start = 0, end = n - 1;
        while(start < end) {
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }

    // Row wise reverse
    for(int i = 0; i < n; i++) {
        int start = 0, end = n - 1;
        while(start <= end) {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate(matrix);

    cout << "Rotated Matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// output:
// 9 8 7
// 6 5 4
// 3 2 1
// ............................................................................................
// Rotate by 90 degree (https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1?utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat){
  	int n = mat.size();
  
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][n - 1 - i];
            mat[j][n - 1 - i] = mat[n - 1 - i][n - 1 - j];
            mat[n - 1 - i][n - 1 - j] = mat[n - 1 - j][i];
            mat[n - 1 - j][i] = temp;
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(mat);

    cout << "Rotated Matrix:" << endl;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// output:
// Rotated Matrix:
// 4 8 12 16 
// 3 7 11 15 
// 2 6 10 14 
// 1 5 9 13 
// ............................................................................................
// Rotate Matrix k times (https://www.geeksforgeeks.org/dsa/rotate-ring-matrix-anticlockwise-k-elements/)

