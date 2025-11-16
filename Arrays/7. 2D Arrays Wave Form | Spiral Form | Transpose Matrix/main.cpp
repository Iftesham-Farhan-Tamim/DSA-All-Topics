// Create 2d vector

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int> > matrix(3, vector<int> (4, 1));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
    }
}

// output:
// 1 1 1 1 1 1 1 1 1 1 1 1
// ............................................................................................
// Find the number of rows and columns in a 2D vector (matrix)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int> > matrix(3, vector<int>(4, 1));
    
    cout << "Rows = " << matrix.size();
    cout << endl;
    cout << "Cols = " << matrix[0].size();
    cout << endl;
}

// output:
// Rows = 3
// Cols = 4
// ............................................................................................
// Input and Output of a 2D Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter rows and cols: ";
    cin >> n >> m;
    vector<vector<int> > matrix(n, vector<int>(m, 1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// input:
// Enter rows and cols: 3 4
// 2 3 1 4 5 5 4 1 8 91 10 11

// output:
// 2 3 1 4 
// 5 5 4 1 
// 8 91 10 11
// ............................................................................................
// Wave Print of a 2D Matrix

#include <bits/stdc++.h>
using namespace std;

void wave(int arr[][4], int row, int col) {
    for(int j = 0; j < col; j++) {
        if(j % 2 == 0) {
            for(int i = 0; i < row; i++) {
                cout << arr[i][j] << " ";
            }
        } else {
            for(int i = row - 1; i >= 0; i--) {
                cout << arr[i][j] << " ";
            }
        }
    }
}

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int row = 3, col = 4;
    cout << "Wave Print: ";
    wave(arr, row, col);
}

// output:
// Wave Print: 1 5 9 10 6 2 3 7 11 12 8 4
// ............................................................................................
// Spiral Matrix (https://leetcode.com/problems/spiral-matrix/description/)

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int top = 0, bottom = row - 1, left = 0, right = col - 1;

    while(left <= right && top <= bottom) {
        // print top
        for(int j = left; j <= right; j++) {
            ans.push_back(matrix[top][j]);
            top++;
        }

        // print right
        for(int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
            right--;
        }

        // print bottom
        if(top <= bottom) {
            for(int j = right; j >= left; j--) {
                ans.push_back(matrix[bottom][j]);
                bottom--;
            }
        }

        // print left
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
                left++;
            }
        }
    }

    return ans;
}

int main() {
     vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;
}

// output:
// 1 2 3 6 9 8 7 4 5 
// ............................................................................................
// Transpose of Matrix (https://www.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1?utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int> > &matrix, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = matrix.size();
    transpose(matrix, n);

    cout << "Transposed Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// output:
// 1 4 7 
// 2 5 8 
// 3 6 9 
